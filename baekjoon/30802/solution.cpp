#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(6);
    for (int &a: a) cin >> a;
    int t, p; cin >> t >> p;
    int ans = 0;
    for (int a: a) ans += (a + t - 1) / t;
    cout << ans << '\n';
    cout << n / p << ' ' << n % p << '\n';
}