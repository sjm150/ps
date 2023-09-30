#include <bits/stdc++.h>
using namespace std;
const int inf = 123456789;

int b[100001];
int vst[100001];
int grp[100001];
vector<int> csize(1, inf);

int cyc_dfs(int v, int cur) {
    vst[cur] = v;
    int nxt = b[cur];
    if (vst[nxt] >= 0) {
        if (grp[nxt] >= 0) {
            return grp[cur] = grp[nxt];
        } else {
            grp[cur] = csize.size();
            csize.push_back(vst[cur] - vst[nxt] + 1);
            return grp[cur];
        }
    } else {
        return grp[cur] = cyc_dfs(v + 1, nxt);
    }
}

bool solve(int n, int k) {
    if (k == 1) {
        for (int i = 1; i <= n; i++) {
            if (b[i] != 0 && b[i] != i) return false;
        }
    } else {
        fill(vst, vst + n + 1, -1);
        fill(grp, grp + n + 1, -1);
        vst[0] = 0;
        grp[0] = 0;
        csize = vector<int>(1, inf);
        for (int i = 1; i <= n; i++) {
            if (b[i] && vst[i] < 0 && csize[cyc_dfs(0, i)] != k) return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> b[i];
        if (solve(n, k)) cout << "YES\n";
        else cout << "NO\n";
    }
}