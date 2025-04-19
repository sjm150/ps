#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    int n; cin >> n;
    vector<pi> wh(n);
    for (auto &[w, h]: wh) cin >> w >> h;
    sort(wh.begin(), wh.end());
    vector<pi> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && stk.back().first <= wh[i].second) stk.pop_back();
        stk.emplace_back(wh[i].second, i);
    }
    int sz = stk.size();
    for (int i = 0; i < sz; i++) wh[i] = wh[stk[i].second];
    wh.resize(sz);

    typedef long long ll;
    typedef struct Linear {
        ll a, b, s;
        Linear(ll a, ll b): a(a), b(b), s(0) {}
    } ln_t;
    auto cpx = [](ln_t &f, ln_t &g) {
        return (g.b - f.b + f.a - g.a - 1) / (f.a - g.a);
    };

    vector<ln_t> lstk;
    vector<ll> sum(sz + 1);
    sum[0] = 0;
    int idx = 0;
    for (int i = 0; i < sz; i++) {
        ln_t ln(wh[i].second, sum[i]);
        while (!lstk.empty()) {
            ll x = cpx(lstk.back(), ln);
            if (lstk.back().s < x) {
                ln.s = x;
                break;
            }
            lstk.pop_back();
        }
        lstk.push_back(ln);

        idx = min(idx, int(lstk.size() - 1));
        while (idx + 1 < int(lstk.size()) && lstk[idx + 1].s <= wh[i].first) idx++;

        sum[i + 1] = lstk[idx].a * wh[i].first + lstk[idx].b;
    }

    cout << sum[sz] << '\n';
}