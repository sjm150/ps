#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef struct Fwtree {
        vector<int> val;
        Fwtree(int n): val(n + 1, 0) {}
        void add(int i, int v) {
            i++;
            while (i < val.size()) {
                val[i] += v;
                i += i & -i;
            }
        }
        int get(int i) {
            i++;
            int ret = 0;
            while (i) {
                ret += val[i];
                i &= i - 1;
            }
            return ret;
        }
    } fwt_t;
    typedef long long ll;

    int n; cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    auto u = a;
    sort(u.begin(), u.end());
    int sz = unique(u.begin(), u.end()) - u.begin();
    u.resize(sz);
    auto idx = [&](int v) {
        return lower_bound(u.begin(), u.end(), v) - u.begin();
    };


    fwt_t lt(sz), rt(sz);
    for (int a: a) rt.add(idx(a), 1);
    ll ans = 0;
    for (int a: a) {
        int i = idx(a);
        rt.add(i, -1);
        ans += rt.get(i - 1) * ll(lt.get(sz - 1) - lt.get(i));
        lt.add(i, 1);
    }
    cout << ans << '\n';
}