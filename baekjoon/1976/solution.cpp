#include <bits/stdc++.h>
using namespace std;

typedef struct Djset {
    vector<int> p;
    Djset(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    void uni(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        p[a] = b;
    }
} djs_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    djs_t djs(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int c; cin >> c;
            if (c == 1) djs.uni(i, j);
        }
    }

    int s; cin >> s;
    m--;
    bool poss = true;
    while (m--) {
        int v; cin >> v;
        if (djs.find(s) != djs.find(v)) poss = false;
    }

    if (poss) cout << "YES\n";
    else cout << "NO\n";
}