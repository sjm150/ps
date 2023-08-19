#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> dst;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a, b; cin >> a >> b;
    queue<int> q;
    dst[b] = 1;
    q.push(b);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur < a) continue;
        if (cur % 2 == 0) {
            dst[cur / 2] = dst[cur] + 1;
            q.push(cur / 2);
        }
        if (cur % 10 == 1) {
            dst[cur / 10] = dst[cur] + 1;
            q.push(cur / 10);
        }
    }
    if (dst.find(a) != dst.end()) cout << dst[a] << '\n';
    else cout << -1 << '\n';
}