#include <bits/stdc++.h>
using namespace std;

int n;
int lvl[1000001];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int m; cin >> n >> m;
    queue<int> q;
    while (m--) {
        int p; cin >> p;
        lvl[p] = 1;
        q.push(p);
    }
    while (!q.empty()) {
        int p = q.front(); q.pop();
        for (int b = 1; b <= n; b <<= 1) {
            for (int np: {p | b, p & (~b)}) {
                if (np > n || lvl[np]) continue;
                lvl[np] = lvl[p] + 1;
                q.push(np);
            }
        }
    }
    int maxlvl = 0;
    for (int i = 0; i <= n; i++) maxlvl = max(maxlvl, lvl[i]);
    cout << maxlvl - 1 << '\n';
}