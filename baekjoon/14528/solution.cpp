#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<string> s(n), p(n);
    for (auto &s: s) cin >> s;
    for (auto &p: p) cin >> p;

    auto val = [](char c) {
        if (c == 'A') return 0;
        else if (c == 'C') return 1;
        else if (c == 'G') return 2;
        else return 3;
    };

    vector<bool> spt(64);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                fill(spt.begin(), spt.end(), false);
                for (auto &s: s) spt[val(s[i]) * 16 + val(s[j]) * 4 + val(s[k])] = true;
                bool poss = true;
                for (auto &p: p) {
                    if (spt[val(p[i]) * 16 + val(p[j]) * 4 + val(p[k])]) {
                        poss = false;
                        break;
                    }
                }
                if (poss) ans++;
            }
        }
    }

    cout << ans << '\n';
}