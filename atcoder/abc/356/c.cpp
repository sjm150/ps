#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    vector<int> c(m);
    vector<vector<int>> a(m);
    vector<char> r(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i];
        a[i].resize(c[i]);
        for (int &a: a[i]) {
            cin >> a;
            a--;
        }
        cin >> r[i];
    }

    int ans = 0;
    int mx = 1 << n;
    for (int i = 0; i < mx; i++) {
        bool poss = true;
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int a: a[j]) {
                if ((1 << a) & i) cnt++;
            }
            if ((cnt >= k) != (r[j] == 'o')) {
                poss = false;
                break;
            }
        }
        if (poss) ans++;
    }

    cout << ans << '\n';
}