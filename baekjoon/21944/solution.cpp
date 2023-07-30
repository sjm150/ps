#include <iostream>
#include <set>
typedef long long lint;
using namespace std;

set<pair<int, int>> pset;
set<pair<int, int>> gpset[101];
pair<int, int> lgofp[100001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    while (n--) {
        int p, l, g; cin >> p >> l >> g;
        pset.insert({l, p});
        gpset[g].insert({l, p});
        lgofp[p] = {l, g};
    }
    int m; cin >> m;
    while (m--) {
        string cmd; cin >> cmd;
        if (cmd == "recommend") {
            int g, x; cin >> g >> x;
            if (x == 1) cout << prev(gpset[g].end())->second << '\n';
            else cout << gpset[g].begin()->second << '\n';
        } else if (cmd == "recommend2") {
            int x; cin >> x;
            if (x == 1) cout << prev(pset.end())->second << '\n';
            else cout << pset.begin()->second << '\n';
        } else if (cmd == "recommend3") {
            int x, l; cin >> x >> l;
            if (x == 1) {
                auto it = pset.lower_bound({l, 0});
                if (it != pset.end()) cout << it->second << '\n';
                else cout << -1 << '\n';
            } else {
                auto it = pset.upper_bound({l, 0});
                if (it != pset.begin()) cout << prev(it)->second << '\n';
                else cout << -1 << '\n';
            }
        } else if (cmd == "add") {
            int p, l, g; cin >> p >> l >> g;
            pset.insert({l, p});
            gpset[g].insert({l, p});
            lgofp[p] = {l, g};
        } else {
            int p; cin >> p;
            auto [l, g] = lgofp[p];
            pset.erase({l, p});
            gpset[g].erase({l, p});
        }
    }
}