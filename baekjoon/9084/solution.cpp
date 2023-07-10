#include <iostream>

using namespace std;

int kind[20];
int num[10001][20];

int get_num(int n, int m) {
    if (m == 0) return 1;
    if (n < 0) return 0;
    int& ret = num[m][n];
    if (ret >= 0) return ret;
    ret = 0;
    for (int i = 0; i <= m; i += kind[n]) ret += get_num(n - 1, m - i);
    return ret;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> kind[i];
        cin >> m;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                num[i][j] = -1;
            }
        }
        cout << get_num(n - 1, m) << '\n';
    }
}