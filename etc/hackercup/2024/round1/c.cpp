#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int T; cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        ll w, g, l; cin >> w >> g >> l;
        cout << "Case #" << testcase << ": "  << (1 + 2 * l) % mod * ((w - g) % mod) % mod << '\n';
    }
}