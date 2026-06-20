#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, int>> lh(n);
    for (auto &[l, h]: lh) cin >> h >> l;
    sort(lh.begin(), lh.end());
    for (int i = n - 2; i >= 0; i--) lh[i].second = max(lh[i].second, lh[i + 1].second);
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        cout << lower_bound(lh.begin(), lh.end(), make_pair(t + 1, 0))->second << '\n';
    }
}