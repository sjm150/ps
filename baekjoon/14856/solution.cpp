#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll n; cin >> n;
    vector<ll> f = {1, 2};
    while (f.back() < n) f.push_back(f.back() + f[f.size() - 2]);
    vector<int> ans;
    for (int i = f.size() - 1; i >= 0; i--) {
        if (f[i] <= n) {
            ans.push_back(i);
            n -= f[i];
            i--;
        }
    }
    if (n == 0) {
        cout << ans.size() << '\n';
        reverse(ans.begin(), ans.end());
        for (int i: ans) cout << f[i] << ' ';
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}