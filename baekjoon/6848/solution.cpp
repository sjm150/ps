#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> edges(n);
    for (;;) {
        int x, y;
        cin >> x >> y;
        if (x == 0) break;
        edges[x - 1].push_back(y - 1);
    }
    vector<int> cnt(n, 0);
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int nxt: edges[i]) cnt[nxt] += cnt[i];
    }
    cout << cnt[n - 1] << '\n';
}