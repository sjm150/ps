#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    vector<ll> ps;
    for (int l = 1; l < 18; l += 2) {
        string s(l, ' ');
        for (int i = 1; i + l / 2 < 10; i++) {
            for (int j = 0; j <= l / 2; j++) s[j] = s[l - 1 - j] = '0' + i + j;
            ps.push_back(stoll(s));
        }
    }
    int T; cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        ll a, b; cin >> a >> b;
        int m; cin >> m;
        int cnt = 0;
        for (ll p: ps) {
            if (a <= p && p <= b && p % m == 0) cnt++;
        }
        cout << "Case #" << testcase << ": "  << cnt << '\n';
    }
}