#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, c; cin >> n >> c;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        a[0] += c;

        vector<ll> suma(n);
        suma[0] = 0;
        for (int i = 1; i < n; i++) suma[i] = suma[i - 1] + a[i - 1];

        int mxi = max_element(a.begin(), a.end()) - a.begin();
        int mxu = -1;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            if (i == mxi) {
                ans[i] = 0;
            } else if (mxu < 0 || (a[i] + suma[i] >= a[mxu])) {
                ans[i] = i;
            } else {
                ans[i] = i + 1;
            }
            if (mxu < 0 || a[mxu] <= a[i]) mxu = i;
        }

        for (int a: ans) cout << a << ' ';
        cout << '\n';
    }
}