#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
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

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    vector<pair<int, int>> ord(n);
    for (int i = 0; i < n; i++) ord[i] = {a[i], i};
    sort(ord.begin(), ord.end());
    for (int i = 0; i < n; i++) a[ord[i].second] = i;

    long long ans = 0;
    fwt_t fwt(n);
    for (int a: a) {
        ans += fwt.get(n - 1) - fwt.get(a);
        fwt.add(a);
    }
    cout << ans << '\n';
}