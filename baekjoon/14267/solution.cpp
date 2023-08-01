#include <iostream>
using namespace std;

int p[100001];
int amount[100001];
int total[100001];
void dfs(int cur) {
    if (total[p[cur]] < 0) dfs(p[cur]);
    total[cur] = total[p[cur]] + amount[cur];
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> p[i];
    while (m--) {
        int i, w; cin >> i >> w;
        amount[i] += w;
    }
    for (int i = 1; i <= n; i++) total[i] = -1;
    for (int i = 1; i <= n; i++) {
        if (total[i] < 0) dfs(i);
        cout << total[i] << ' ';
    }
    cout << '\n';
}