#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int &a: a) cin >> a;
        for (int &b: b) cin >> b;

        int ar = 0, br = 0;
        int inc = 0, dec = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) ar += a[i];
            else if (a[i] < b[i]) br += b[i];
            else if (a[i] > 0) inc++;
            else if (a[i] < 0) dec++;
        }

        while (inc--) {
            if (ar > br) br++;
            else ar++;
        }
        while (dec--) {
            if (ar > br) ar--;
            else br--;
        }

        cout << min(ar, br) << '\n';
    }
}