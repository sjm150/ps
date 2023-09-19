#include <bits/stdc++.h>
using namespace std;

int cnt[1000001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    queue<int> q;
    cnt[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur + u <= f && cnt[cur + u] == 0) {
            cnt[cur + u] = cnt[cur] + 1;
            q.push(cur + u);
        }
        if (cur - d > 0 && cnt[cur - d] == 0) {
            cnt[cur - d] = cnt[cur] + 1;
            q.push(cur - d);
        }
    }
    if (cnt[g]) cout << cnt[g] - 1 << '\n' ;
    else cout << "use the stairs\n";
}