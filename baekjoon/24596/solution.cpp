#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1e18;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<vector<pair<int, int>>> xy(k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            xy[x - 1].emplace_back(i, j);
        }
    }
    vector<vector<ll>> dst(n, vector<ll>(n, inf));
    for (auto &[x, y]: xy[0]) dst[x][y] = 0;
    for (int i = 1; i < k; i++) {
        vector<ll> xmn(n, inf), ymn(n, inf);
        for (auto &[x, y]: xy[i - 1]) {
            if (xmn[x] > dst[x][y]) xmn[x] = dst[x][y];
            if (ymn[y] > dst[x][y]) ymn[y] = dst[x][y];
        }
        for (auto &[x, y]: xy[i]) {
            for (int i = 0; i < n; i++) {
                ll d = (i - x) * (i - x) + xmn[i];
                if (dst[x][y] > d) dst[x][y] = d;
                d = (i - y) * (i - y) + ymn[i];
                if (dst[x][y] > d) dst[x][y] = d;
            }
        }
    }
    ll mn = inf;
    for (auto &[x, y]: xy[k - 1]) mn = min(mn, dst[x][y]);
    cout << (mn < inf ? mn : -1) << '\n';
}