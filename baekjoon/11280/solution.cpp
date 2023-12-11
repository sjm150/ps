#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> vst, scc;
int vidx, sidx;

int tarjan(int cur, stack<int>& stk) {
    int minv = vst[cur] = vidx++;
    stk.push(cur);
    for (int nxt: edges[cur]) {
        if (vst[nxt] < 0) {
            minv = min(minv, tarjan(nxt, stk));
        } else if (scc[nxt] < 0) {
            minv = min(minv, vst[nxt]);
        }
    }
    if (minv == vst[cur]) {
        while (!stk.empty() && vst[stk.top()] >= vst[cur]) {
            scc[stk.top()] = sidx;
            stk.pop();
        }
        sidx++;
    }
    return minv;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    edges.resize(2 * n + 1);
    while (m--) {
        int i, j; cin >> i >> j;
        int ni = -i, nj = -j;
        if (i < 0) i = n - i;
        if (j < 0) j = n - j;
        if (ni < 0) ni = n - ni;
        if (nj < 0) nj = n - nj;
        edges[ni].push_back(j);
        edges[nj].push_back(i);
    }

    vst = scc = vector<int>(2 * n + 1, -1);
    stack<int> stk;
    for (int i = 1; i <= 2 * n; i++) {
        if (vst[i] < 0) tarjan(i, stk);
    }

    bool poss = true;
    for (int i = 1; i <= n; i++) {
        if (scc[i] == scc[n + i]) {
            poss = false;
            break;
        }
    }

    cout << (poss ? 1 : 0) << '\n';
}