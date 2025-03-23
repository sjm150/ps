#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mx = 1e5;
    vector<bool> isp(mx + 1, true);
    vector<int> p;
    for (ll i = 2; i <= mx; i++) {
        if (!isp[i]) continue;
        p.push_back(i);
        for (ll j = i * i; j <= mx; j += i) isp[j] = false;
    }
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 2) {
            cout << 2 << ' ' << 1 << '\n';
            continue;
        }
        int x = *lower_bound(p.begin(), p.end(), (n + 2) / 3);
        cout << x << ' ';
        for (int i = 1; i < x; i++) cout << x - i << ' ' << x + i << ' ';
        for (int i = 2 * x; i <= n; i++) cout << i << ' ';
        cout << '\n';
    }
}