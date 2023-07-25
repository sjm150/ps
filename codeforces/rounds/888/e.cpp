#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll c[200001];
vector<bool> vst;
vector<vector<int>> needs;

ll cost(int cur) {
    if (vst[cur]) return c[cur];
    vst[cur] = true;
    if (needs[cur].size() > 0) {
        ll mixc = 0;
        for (int nxt: needs[cur]) mixc += cost(nxt);
        c[cur] = min(c[cur], mixc);
    }
    return c[cur];
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vst = vector<bool>(n + 1, false);
        needs = vector<vector<int>>(n + 1);
        for (int i = 1; i <= n; i++) cin >> c[i];
        for (int i = 0; i < k; i++) {
            int p; cin >> p;
            c[p] = 0;
            vst[p] = true;
        }
        for (int i = 1; i <= n; i++) {
            int m; cin >> m;
            while (m--) {
                int e; cin >> e;
                needs[i].push_back(e);
            }
        }
        for (int i = 1; i <= n; i++) cout << cost(i) << ' ';
        cout << '\n';
    }
}