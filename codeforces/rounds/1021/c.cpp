#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        map<int, int> cnt;
        for (int a: a) cnt[a]++;
        vector<pair<int, int>> c;
        for (auto [a, cnt]: cnt) c.emplace_back(a, cnt);
        int sz = c.size();

        bool ok = false, tmp = false;
        for (int i = 0; i < sz; i++) {
            auto [a, cnt] = c[i];
            if (c[i - 1].first + 1 < a) tmp = false;
            if (cnt >= 4) {
                ok = true;
                break;
            } else if (cnt >= 2) {
                if (tmp) {
                    ok = true;
                    break;
                } else {
                    tmp = true;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}