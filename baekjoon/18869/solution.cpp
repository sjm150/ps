#include <iostream>
#include <algorithm>

using namespace std;

int s[100][10000];
int temp[10000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) temp[j] = s[i][j];
        sort(temp, temp + n);
        for (int j = 0; j < n; j++) s[i][j] = lower_bound(temp, temp + n, s[i][j]) - temp;
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            bool same = true;
            for (int k = 0; k < n; k++) {
                if (s[i][k] != s[j][k]) {
                    same = false;
                    break;
                }
            }
            if (same) cnt++;
        }
    }
    cout << cnt << '\n';
}