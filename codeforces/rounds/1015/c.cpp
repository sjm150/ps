#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int &a: a) {
            cin >> a;
            a--;
        }
        for (int &b: b) {
            cin >> b;
            b--;
        }
        vector<int> p(n);
        for (int i = 0; i < n; i++) p[a[i]] = i;

        int cnt = 0, s = -1;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                cnt++;
                s = i;
            } else if (p[b[p[b[i]]]] != i) {
                ok = false;
                break;
            }
        }
        if (cnt > 1 || (cnt == 1 && n % 2 == 0)) ok = false;

        if (ok) {
            vector<pair<int, int>> ans;
            if (s >= 0) {
                int m = n / 2;
                if (s != m) {
                    swap(a[s], a[m]);
                    swap(b[s], b[m]);
                    swap(p[a[s]], p[a[m]]);
                    ans.emplace_back(s + 1, m + 1);
                }
            }
            for (int i = 0; i < n; i++) {
                int j = n - 1 - i;
                if (a[i] != b[j]) {
                    int k = p[b[i]];
                    swap(a[k], a[j]);
                    swap(b[k], b[j]);
                    swap(p[a[k]], p[a[j]]);
                    ans.emplace_back(k + 1, j + 1);
                }
            }
            cout << ans.size() << '\n';
            for (auto [i, j]: ans) cout << i << ' ' << j << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}