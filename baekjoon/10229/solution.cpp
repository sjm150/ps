#include <bits/stdc++.h>
using namespace std;

int LocateCentre(int n, int p[], int s[], int d[]) {
    vector<vector<int>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        edges[s[i]].push_back(d[i]);
        edges[d[i]].push_back(s[i]);
    }

    int tot = accumulate(p, p + n, 0);
    vector<int> mx(n, 0);
    function<int(int, int)> dfs = [&](int pre, int cur) {
        int sum = p[cur];
        for (int nxt: edges[cur]) {
            if (nxt == pre) continue;
            int cnt = dfs(cur, nxt);
            mx[cur] = max(mx[cur], cnt);
            sum += cnt;
        }
        mx[cur] = max(mx[cur], tot - sum);
        return sum;
    };
    dfs(-1, 0);

    return min_element(mx.begin(), mx.end()) - mx.begin();
}