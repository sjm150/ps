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
                val[i] ^= v;
                i += i & -i;
            }
        }
        int get(int i) {
            i++;
            int ret = 0;
            while (i) {
                ret ^= val[i];
                i &= i - 1;
            }
            return ret;
        }
    } fwt_t;

    int n;
    cin >> n;
    vector<int> x(n);
    for (int &x: x) cin >> x;

    fwt_t fwt(n);

    int m;
    cin >> m;
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b, c;
            cin >> a >> b >> c;
            fwt.add(a, c);
            fwt.add(b + 1, c);
        } else {
            int a;
            cin >> a;
            cout << (x[a] ^ fwt.get(a)) << '\n';
        }
    }
}