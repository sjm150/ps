#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    ll ans = 0;
    int r = 0;
    for (int l = 0; l < n; l++) {
        if (r < l) r++;
        if (r < n - 1 && l == r && a[r] != a[r + 1]) r++;
        while (r < n - 1 && ll(a[r] - a[r - 1]) * (a[r + 1] - a[r]) < 0) r++;
        ans += r - l + 1;
    }
    cout << ans << '\n';
}