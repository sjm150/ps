#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int &a: a) cin >> a;
    for (int &b: b) cin >> b;
    
    typedef long long ll;
    typedef struct Linear {
        ll a, b, s;
        Linear(ll a, ll b): a(a), b(b), s(0) {}
    } ln_t;
    auto cpx = [](ln_t &a, ln_t b) {
        return (b.b - a.b + a.a - b.a - 1) / (a.a - b.a);
    };

    vector<ln_t> stk;
    vector<ll> cst(n);
    cst[0] = 0;
    int idx = 0;
    for (int i = 1; i < n; i++) {
        auto ln = ln_t(b[i - 1], cst[i - 1]);
        while (!stk.empty()) {
            auto x = cpx(stk.back(), ln);
            if (stk.back().s < x) {
                ln.s = x;
                break;
            }
            stk.pop_back();
        }
        stk.push_back(ln);

        idx = min(idx, int(stk.size() - 1));
        while (idx < stk.size() - 1 && stk[idx + 1].s <= a[i]) idx++;

        cst[i] = stk[idx].a * a[i] + stk[idx].b;
    }

    cout << cst[n - 1] << '\n';
}