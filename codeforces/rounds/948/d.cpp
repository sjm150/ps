#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<string> ss(n);
        for (string &s: ss) cin >> s;

        vector<ull> rnd(n);
        for (auto &r: rnd) r = rng();

        vector<pair<ull, int>> hshs;
        for (int j = 0; j < m; j++) {
            ull h = 0;
            for (int i = 0; i < n; i++) {
                if (ss[i][j] == '1') h ^= rnd[i];
            }
            for (int i = 0; i < n; i++) hshs.emplace_back(h ^ rnd[i], i * m + j);
        }
        sort(hshs.begin(), hshs.end());

        int cnt = 0;
        int maxc = 0, idx = 0;
        for (int i = 0; i < n * m; i++) {
            if (i > 0 && hshs[i - 1].first != hshs[i].first) cnt = 0;
            cnt++;
            if (maxc < cnt) {
                maxc = cnt;
                idx = hshs[i].second;
            }
        }

        cout << maxc << '\n';
        int j = idx % m;
        for (int i = 0; i < n; i++) {
            if (i == idx / m) cout << char('0' + '1' - ss[i][j]);
            else cout << ss[i][j];
        }
        cout << '\n';
    }
}