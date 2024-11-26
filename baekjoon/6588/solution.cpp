#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mx = 1e6;
    vector<bool> isp(mx + 1, true);
    vector<int> p;
    for (ll i = 2; i <= mx; i++) {
        if (!isp[i]) continue;
        p.push_back(i);
        for (ll j = i * i; j <= mx; j += i) isp[j] = false;
    }
    for (;;) {
        int n; cin >> n;
        if (!n) break;
        for (int p: p) {
            if (isp[n - p]) {
                cout << n << " = " << p << " + " << n - p << '\n';
                break;
            }
        }
    }
}