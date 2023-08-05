#include <iostream>
#include <cmath>
#include <tuple>
#include <algorithm>
using namespace std;
typedef long long ll;

int p[1001];
int find(int n) {
    if (p[n] == 0) return n;
    p[n] = find(p[n]);
    return p[n];
}
bool uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    p[a] = b;
    return true;
}

int x[1001], y[1001];
tuple<ll, int, int> edges[1000000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cout.precision(2); cout << fixed;
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            edges[idx++] = {ll(x[i] - x[j]) * (x[i] - x[j]) + ll(y[i] - y[j]) * (y[i] - y[j]), i, j};
        }
    }
    sort(edges, edges + idx);
    while (m--) {
        int a, b; cin >> a >> b;
        uni(a, b);
    }
    double sum = 0;
    for (int i = 0; i < idx; i++) {
        auto [w, u, v] = edges[i];
        if (uni(u, v)) sum += sqrt(w);
    }
    cout << sum << '\n';
}