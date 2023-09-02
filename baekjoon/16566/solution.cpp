#include <bits/stdc++.h>
using namespace std;

int p[4000001];
int find(int cur) {
    if (p[cur] == -1) return cur;
    return p[cur] = find(p[cur]);
}
void uni(int a, int b) {
    a = find(a), b = find(b);
    p[b] = a;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    while (m--) {
        int v; cin >> v;
        p[v] = -1;
    }
    int pr = n + 1;
    p[pr] = -1;
    for (int i = n; i >= 1; i--) {
        if (p[i] == -1) pr = i;
        else p[i] = pr;
    }
    while (k--) {
        int v; cin >> v;
        int r = find(v + 1);
        cout << r << '\n';
        uni(r + 1, r);
    }
}