#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mod = 998244353;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        int h = 0, l = 1, lcnt = 1;
        if (a[0] == 0) h++;
        for (int i = 1; i < n; i++) {
            int nh = 0;
            if (a[i - 1] == a[i]) nh = (nh + h) % mod;
            if (lcnt == a[i]) nh = (nh + l) % mod;
            l = h;
            lcnt = a[i - 1] + 1;
            h = nh;
        }
        cout << (h + l) % mod << '\n';
    }
}