#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<int>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> c(n), r;
    for (int i = 0; i < n; i++) {
        c[i] = edges[i].size();
        if (c[i] == 1) r.push_back(i);
    }
    while (r.size() > 2) {
        vector<int> nr;
        for (int i: r) {
            c[i] = -1;
            for (int nxt: edges[i]) {
                if (c[nxt] > 0) {
                    c[nxt]--;
                    if (c[nxt] == 1) nr.push_back(nxt);
                }
            }
        }
        swap(nr, r);
    }
    for (int i = 0; i < n; i++) {
        if (c[i] >= 0) cout << i << ' ';
    }
    cout << '\n';
}