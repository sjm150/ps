#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> vst, scc;
int vidx, sidx;

int tarjan(int cur, stack<int> &stk) {
    int rch = vst[cur] = vidx++;
    stk.push(cur);
    for (int nxt: edges[cur]) {
        if (vst[nxt] < 0) rch = min(rch, tarjan(nxt, stk));
        else if (scc[nxt] < 0) rch = min(rch, vst[nxt]);
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

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int k, n; cin >> k >> n;
    edges.resize(2 * k + 1);
    while (n--) {
        int u[3], nu[3];
        char c[3];
        for (int i = 0; i < 3; i++) {
            cin >> u[i] >> c[i];
            if (c[i] == 'R') {
                nu[i] = u[i] + k;
            } else {
                nu[i] = u[i];
                u[i] += k;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                edges[nu[i]].push_back(u[j]);
            }
        }
    }

    vst = scc = vector<int>(2 * k + 1, -1);
    stack<int> stk;
    for (int i = 1; i <= 2 * k; i++) {
        if (vst[i] < 0) tarjan(i, stk);
    }

    vector<pair<int, int>> ord;
    for (int i = 1; i <= k; i++) {
        if (scc[i] == scc[i + k]) {
            cout << -1 << '\n';
            return 0;
        }
        ord.emplace_back(scc[i], i);
        ord.emplace_back(scc[i + k], i + k);
    }
    sort(ord.begin(), ord.end());

    vector<int> clr(k + 1, -1);
    for (auto &[_s, i]: ord) {
        int &c = clr[(i - 1) % k + 1];
        if (c < 0) c = i > k;
    }

    for (int i = 1; i <= k; i++) cout << "RB"[clr[i]];
    cout << '\n';
}