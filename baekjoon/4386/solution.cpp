#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> pd;
typedef tuple<double, int, int> edge;

pd coord[100];
edge edges[10000];

int p[100];
int find(int x) {
    if (p[x] == -1) return x;
    return p[x] = find(p[x]);
}
bool uni(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    p[a] = b;
    return true;
}

double dst(pd p1, pd p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> coord[i].first >> coord[i].second;
    fill(p, p + n, -1);
    int eidx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges[eidx++] = {dst(coord[i], coord[j]), i, j};
        }
    }
    sort(edges, edges + eidx);
    double sum = 0;
    int cnt = 0;
    for (int i = 0; i < eidx; i++) {
        auto [d, idx, jdx] = edges[i];
        if (!uni(idx, jdx)) continue;
        sum += d;
        cnt++;
        if (cnt == n - 1) continue;
    }
    cout << fixed << setprecision(4);
    cout << sum << '\n';
}