#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        int mxv = 0;
        for (int i = 1; i < n; i++) {
            mxv = max(mxv, min(a[i - 1], a[i]));
        }
        for (int i = 2; i < n; i++) {
            int b[] = {a[i - 2], a[i - 1], a[i]};
            sort(b, b + 3);
            mxv = max(mxv, b[1]);
        }
        cout << mxv << '\n';
    }
}