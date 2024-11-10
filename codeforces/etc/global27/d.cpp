#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mod = 1e9 + 7;
    function<ll(int)> exn2 = [&](int e) {
        ll ret = 1, x = 2;
        for (; e; e /= 2) {
            if (e % 2) ret = ret * x % mod;
            x = x * x % mod;
        }
        return ret;
    };
    function<int(int, int, int, int)> cmp = [&](int a, int ae, int b, int be) {
        int mn = min(ae, be);
        ae -= mn, be -= mn;
        if (ae) {
            if (ae > 30 || (1ll << ae) * a > b) return -1;
            else if ((1ll << ae) * a == b) return 0;
            else return 1;
        } else {
            if (be > 30 || (1ll << be) * b > a) return 1;
            else if ((1ll << be) * b == a) return 0;
            else return -1;
        }
    };

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        int sum = 0;
        stack<pair<int, int>> stk;
        for (int a: a) {
            int bse = a, cnt = 0;
            for (; bse % 2 == 0; bse /= 2) cnt++;
            while (!stk.empty() && cmp(stk.top().first, 0, bse, cnt) >= 0) {
                auto [b, c] = stk.top(); stk.pop();
                cnt += c;
                sum = ((sum - exn2(c) * b + b) % mod + mod) % mod;
            }
            sum = (sum + exn2(cnt) * bse) % mod;
            cout << sum << ' ';
            stk.emplace(bse, cnt);
        }
        cout << '\n';
    }
}