#include <bits/stdc++.h>
using namespace std;
const int mx = 52;
const int inf = 123456789;

int c[mx][mx], f[mx][mx];
vector<int> adj[mx];

int idx(char c) {
    if (c <= 'Z') return c - 'A';
    else return c - 'a' + 26;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    while (n--) {
        char a, b;
        int f;
        cin >> a >> b >> f;
        a = idx(a), b = idx(b);
        if (c[a][b] + c[b][a] == 0) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        c[a][b] = c[b][a] += f;
    }

    int tot = 0, s = idx('A'), e = idx('Z');
    while (true) {
        vector<int> pre(mx, -1);
        queue<int> q;
        pre[s] = s;
        q.push(s);
        while (!q.empty() && pre[e] < 0) {
            int cur = q.front(); q.pop();
            for (int nxt: adj[cur]) {
                if (pre[nxt] >= 0 || c[cur][nxt] <= f[cur][nxt]) continue;
                pre[nxt] = cur;
                q.push(nxt);
            }
        }

        if (pre[e] < 0) break;
        int flw = inf;
        for (int cur = e; cur != s; cur = pre[cur]) {
            flw = min(flw, c[pre[cur]][cur] - f[pre[cur]][cur]);
        }
        for (int cur = e; cur != s; cur = pre[cur]) {
            f[pre[cur]][cur] += flw;
            f[cur][pre[cur]] -= flw;
        }
        tot += flw;
    }
    cout << tot << '\n';
}