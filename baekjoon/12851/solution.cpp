#include <bits/stdc++.h>
using namespace std;

int dst[100001];
int cnt[100001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    queue<int> q;
    dst[n] = 1;
    cnt[n] = 1;
    q.push(n);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        int nxts[3] = {cur - 1, cur + 1, 2 * cur};
        for (int nxt: nxts) {
            if (0 <= nxt && nxt <= 100000) {
                if (dst[nxt] == 0) {
                    dst[nxt] = dst[cur] + 1;
                    cnt[nxt] = cnt[cur];
                    q.push(nxt);
                } else if (dst[nxt] == dst[cur] + 1) {
                    cnt[nxt] += cnt[cur];
                }
            }
        }
    }
    cout << dst[k] - 1 << '\n' << cnt[k] << '\n';
}