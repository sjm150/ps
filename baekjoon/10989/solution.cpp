#include <iostream>

using namespace std;

int cnts[10001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        cnts[num]++;
    }
    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < cnts[i]; j++) {
            cout << i << '\n';
        }
    }
}