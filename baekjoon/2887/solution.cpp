#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> p(100000, -1);
pair<int, int> xp[100000], yp[100000], zp[100000];
vector<tuple<int, int, int>> edges;

int find(int i) {
    if (p[i] < 0) return i;
    return p[i] = find(p[i]);
}
bool uni(int i, int j) {
    i = find(i), j = find(j);
    if (i == j) return false;
    p[i] = j;
    return true;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;
        xp[i] = {x, i};
        yp[i] = {y, i};
        zp[i] = {z, i};
    }
    sort(xp, xp + n);
    sort(yp, yp + n);
    sort(zp, zp + n);
    for (int i = 1; i < n; i++) edges.push_back({xp[i].first - xp[i - 1].first, xp[i - 1].second, xp[i].second});
    for (int i = 1; i < n; i++) edges.push_back({yp[i].first - yp[i - 1].first, yp[i - 1].second, yp[i].second});
    for (int i = 1; i < n; i++) edges.push_back({zp[i].first - zp[i - 1].first, zp[i - 1].second, zp[i].second});
    sort(edges.begin(), edges.end());
    ll sum = 0;
    for (auto [w, u, v]: edges) {
        if (uni(u, v)) sum += w;
    }
    cout << sum << '\n';
}