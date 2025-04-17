#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    typedef struct Linear {
        ll a, b, s;
        Linear(ll a, ll b): a(a), b(b), s(0) {}
    } ln_t;
    auto cpx = [](ln_t &f, ln_t &g) {
        return (g.b - f.b + f.a - g.a - 1) / (f.a - g.a);
    };

    int n, a, b, c; cin >> n >> a >> b >> c;
    vector<int> x(n);
    for (int &x: x) cin >> x;
    vector<ll> psum(n + 1);
    psum[0] = 0;
    for (int i = 0; i < n; i++) psum[i + 1] = psum[i] + x[i];

    vector<ln_t> stk;
    vector<ll> sum(n + 1);
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        auto ln = ln_t(-2 * a * psum[i - 1], sum[i - 1] + a * psum[i - 1] * psum[i - 1] - b * psum[i - 1]);
        while (!stk.empty()) {
            auto x = cpx(stk.back(), ln);
            if (stk.back().s < x) {
                ln.s = x;
                break;
            }
            stk.pop_back();
        }
        stk.push_back(ln);

        int l = 0, r = stk.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (stk[m].s <= psum[i]) l = m + 1;
            else r = m;
        }

        sum[i] = stk[r - 1].a * psum[i] + stk[r - 1].b + a * psum[i] * psum[i] + b * psum[i] + c;
    }

    cout << sum[n] << '\n';
}