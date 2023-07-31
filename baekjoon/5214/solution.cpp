#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dst[100001];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k, m; cin >> n >> k >> m;
    vector<vector<int>> stoh(n + 1), htos(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            int s; cin >> s;
            stoh[s].push_back(i);
            htos[i].push_back(s);
        }
    }
    queue<int> q;
    vector<bool> vst(m);
    dst[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int h: stoh[cur]) {
            if (!vst[h]) {
                vst[h] = true;
                for (int nxt: htos[h]) {
                    if (dst[nxt] == 0) {
                        dst[nxt] = dst[cur] + 1;
                        q.push(nxt);
                    }
                }
            }
        }
    }
    if (dst[n] == 0) cout << -1 << '\n';
    else cout << dst[n] << '\n';
}