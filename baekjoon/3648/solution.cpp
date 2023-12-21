#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> edges;
vector<int> vst, scc;
int vidx, sidx;

int tarjan(int cur, stack<int>& stk) {
    int rch = vst[cur] = vidx++;
    stk.push(cur);
    for (int nxt: edges[cur]) {
        if (vst[nxt] < 0) {
            rch = min(rch, tarjan(nxt, stk));
        } else if (scc[nxt] < 0) {
            rch = min(rch, vst[nxt]);
        }
    }
    if (rch == vst[cur]) {
        while (!stk.empty() && vst[stk.top()] >= vst[cur]) {
            scc[stk.top()] = sidx;
            stk.pop();
        }
        sidx++;
    }
    return rch;
}

bool check() {
    vst = scc = vector<int>(2 * n + 1, -1);
    stack<int> stk;
    for (int i = 1; i <= 2 * n; i++) {
        if (vst[i] < 0) tarjan(i, stk);
    }

    for (int i = 1; i <= n; i++) {
        if (scc[i] == scc[n + i]) return false;
    }

    fill(vst.begin(), vst.end(), 0);
    queue<int> q;
    vst[1] = true;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        int ncur;
        if (cur <= n) ncur = n + cur;
        else ncur = cur - n;
        if (vst[ncur]) return false;
        for (int nxt: edges[cur]) {
            if (vst[nxt]) continue;
            vst[nxt] = 1;
            q.push(nxt);
        }
    }

    return true;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    while (cin >> n) {
        int m; cin >> m;
        edges = vector<vector<int>>(2 * n + 1);
        while (m--) {
            int a, b; cin >> a >> b;
            int na = -a, nb = -b;
            if (a < 0) a = n - a;
            else na = n - na;
            if (b < 0) b = n - b;
            else nb = n - nb;
            edges[na].push_back(b);
            edges[nb].push_back(a);
        }

        if (check()) cout << "yes\n";
        else cout << "no\n";
    }
}