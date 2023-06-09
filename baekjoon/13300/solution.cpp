#include <iostream>

using namespace std;

int group[2][6];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int s, y;
        cin >> s >> y;
        group[s][y - 1]++;
    }

    int count = 0;
    for (int s = 0; s < 2; s++) {
        for (int y = 0; y < 6; y++) {
            count += (group[s][y] + k - 1) / k;
        }
    }

    cout << count << '\n';
}