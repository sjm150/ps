#include <bits/stdc++.h>
using namespace std;

typedef struct Djset {
    vector<int> p;
    Djset(int n) {
        p = vector<int>(n);
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
    while (m--) {
        int c, a, b; cin >> c >> a >> b;
        if (c == 0) {
            djs.uni(a, b);
        } else {
            if (djs.find(a) == djs.find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}