#include <iostream>
#include <queue>
using namespace std;

int dst[101];
int mv[101];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int k = n + m;
    while (k--) {
        int x, y; cin >> x >> y;
        mv[x] = y;
    }
    queue<int> q;
    dst[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt = cur + 1; nxt <= min(cur + 6, 100); nxt++) {
            if (dst[nxt] == 0) {
                dst[nxt] = dst[cur] + 1;
                if (mv[nxt] != 0) {
                    if (dst[mv[nxt]] == 0) {
                        dst[mv[nxt]] = dst[nxt];
                        q.push(mv[nxt]);
                    }
                } else {
                    q.push(nxt);
                }
            }
        }
    }
    cout << dst[100] - 1 << '\n';
}