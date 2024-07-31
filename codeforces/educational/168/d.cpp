#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        vector<vector<int>> edges(n);
        for (int i = 1; i < n; i++) {
            int p; cin >> p;
            edges[p - 1].push_back(i);
        }
        function<int(int)> dfs = [&](int cur) {
            if (edges[cur].empty()) return a[cur];
            int mn = 1e9;
            for (int nxt: edges[cur]) mn = min(mn, dfs(nxt));
            if (a[cur] > mn) return mn;
            else return (a[cur] + mn) / 2;
        };
        int mn = 1e9;
        for (int nxt: edges[0]) mn = min(mn, dfs(nxt));
        cout << a[0] + mn << '\n';
    }
}