#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        int minl = n, l = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == a[0]) {
                l++;
            } else {
                if (l) minl = min(minl, l);
                l = 0;
            }
        }
        if (l) minl = min(minl, l);

        cout << (minl == n ? -1 : minl) << '\n';
    }
}