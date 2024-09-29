#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        int omx = 0, emx = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2) omx = max(omx, a[i]);
            else emx = max(emx, a[i]);
        }
        cout << max(omx + n / 2, emx + (n + 1) / 2) << '\n';
    }
}