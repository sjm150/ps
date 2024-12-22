#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> h(n + 1, 0);
    h[1] = 0;
    for (int i = 2; i <= n; i++) {
        cout << 2 << '\n';
        cout << 1 << ' ' << i << endl;
        cin >> h[i];
        h[i]--;
    }
    int sz = *max_element(h.begin(), h.end()) + 1;
    vector<vector<int>> hv(sz);
    for (int i = 1; i <= n; i++) hv[h[i]].push_back(i);
    vector<int> p(n + 1);
    for (int v: hv[1]) p[v] = 1;
    for (int h = 2; h < sz; h++) {
        for (int v: hv[h]) {
            int l = 0, r = hv[h - 1].size();
            while (l < r) {
                int m = (l + r) / 2;
                set<int> q = {1, v};
                function<void(int)> dfs = [&](int cur) {
                    q.insert(cur);
                    if (q.find(p[cur]) == q.end()) dfs(p[cur]);
                };
                for (int i = l; i <= m; i++) dfs(hv[h - 1][i]);
                cout << q.size() << '\n';
                for (int u: q) cout << u << ' ';
                cout << endl;
                int c; cin >> c;
                if (c == q.size()) r = m;
                else l = m + 1;
            }
            p[v] = hv[h - 1][r];
        }
    }
    cout << "!\n";
    for (int i = 2; i <= n; i++) cout << p[i] << ' ' << i << '\n';
    cout.flush();
}