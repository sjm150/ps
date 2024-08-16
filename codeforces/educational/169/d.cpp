#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    map<char, int> cidx = {{'B', 0}, {'G', 1}, {'R', 2}, {'Y', 3}};
    map<string, int> sidx = {{"BG", 0}, {"BR", 1}, {"BY", 2}, {"GR", 3}, {"GY", 4}, {"RY", 5}};
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<string> tp(n + 1);
        vector<vector<int>> v(6);
        for (int i = 1; i <= n; i++) {
            cin >> tp[i];
            v[sidx[tp[i]]].push_back(i);
        }
        while (q--) {
            int x, y; cin >> x >> y;
            vector<bool> xc(4, false), yc(4, false);
            xc[cidx[tp[x][0]]] = xc[cidx[tp[x][1]]] = true;
            yc[cidx[tp[y][0]]] = yc[cidx[tp[y][1]]] = true;
            bool ok = false;
            for (int i = 0; i < 4; i++) {
                if (xc[i] && yc[i]) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                cout << abs(x - y) << '\n';
            } else {
                int ans = inf;
                for (auto &[s, i]: sidx) {
                    if ((xc[cidx[s[0]]] && yc[cidx[s[1]]]) || (xc[cidx[s[1]]] && yc[cidx[s[0]]])) {
                        int cnd[] = {x, y};
                        for (int c: cnd) {
                            auto it = lower_bound(v[i].begin(), v[i].end(), c);
                            if (it != v[i].end()) ans = min(ans, abs(*it - x) + abs(*it - y));
                            if (it != v[i].begin()) {
                                it--;
                                ans = min(ans, abs(*it - x) + abs(*it - y));
                            }
                        }
                    }
                }
                cout << (ans < inf ? ans : -1) << '\n';
            }
        }
    }
}