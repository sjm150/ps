#include <iostream>

using namespace std;

int n;
int score[300];
int excep[300];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> score[i];
        total += score[i];
    }
    if (n < 3) {
        cout << total << '\n';
        return 0;
    }
    excep[0] = score[0];
    excep[1] = score[1];
    excep[2] = score[2];
    for (int i = 3; i < n; i++) {
        excep[i] = min(excep[i - 2], excep[i - 3]) + score[i];
    }
    cout << total - min(excep[n - 2], excep[n - 3]) << '\n';
}