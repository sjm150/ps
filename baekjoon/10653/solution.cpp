#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int inf = 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<pi> crd(n);
    for (int i = 0; i < n; i++) cin >> crd[i].first >> crd[i].second;

    auto mdst = [crd](int i, int j) {
        return abs(crd[i].first - crd[j].first) + abs(crd[i].second - crd[j].second);
    };

    vector<vector<int>> dst(n, vector<int>(k + 1, inf));
    dst[0][0] = 0;
    for (int i = 1; i < n; i++) {
        for (int ii = 0; ii < min(i, k + 1); ii++) {
            for (int j = 0; j <= (k - ii); j++) {
                dst[i][j + ii] = min(dst[i][j + ii], dst[i - 1 - ii][j] + mdst(i - 1 - ii, i));
            }
        }
    }

    int ans = inf;
    for (int i = 0; i <= k; i++) ans = min(ans, dst[n - 1][i]);
    cout << ans << '\n';
}