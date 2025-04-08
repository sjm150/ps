#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    typedef struct Fwtree {
        vector<int> val;
        Fwtree(int n): val(n + 1, 0) {}
        void add(int i) {
            i++;
            while (i < val.size()) {
                val[i]++;
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
    ll n, l; cin >> n >> l;
    ll cnt = 0;
    fwt_t fwt(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        a--;
        cnt += i - fwt.get(a);
        fwt.add(a);
    }
    cout << min(cnt + l, n * (n - 1) / 2) << '\n';
}