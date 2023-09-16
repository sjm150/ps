#include <bits/stdc++.h>
using namespace std;

int p[500000];
void init(int n) {
    fill(p, p + n, -1);
}
int find(int x) {
    if (p[x] == -1) return x;
    return p[x] = find(p[x]);
}
bool uni(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    p[b] = a;
    return true;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    init(n);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        if (!uni(a, b) && ans == 0) ans = i;
    }
    cout << ans << '\n';
}