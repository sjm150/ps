#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &a: a) cin >> a;
        for (int &b: b) cin >> b;

        vector<int> mni(n), mxi(n);
        mni[0] = 0;
        for (int i = 1; i < n; i++) mni[i] = (a[mni[i - 1]] > a[i] ? i : mni[i - 1]);
        mxi[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) mxi[i] = (a[mxi[i + 1]] < a[i] ? i : mxi[i + 1]);

        int l = 1, r = n + 1;
        while (l < r) {
            int m = (l + r) / 2;
            bool swpd = false;
            if (m < n && a[mni[m - 1]] < a[mxi[m]]) {
                swap(a[mni[m - 1]], a[mxi[m]]);
                swpd = true;
            }
            int ai = 0, bi = 0;
            for (int i = 0; i < n; i++) {
                if (a[ai] > b[bi]) ai++;
                else bi++;
            }
            if (swpd) swap(a[mni[m - 1]], a[mxi[m]]);
            if (ai < m) r = m;
            else l = m + 1;
        }

        cout << r - 1 << '\n';
    }
}