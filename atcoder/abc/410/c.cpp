#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    int r = 0;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            a[(p - 1 + r) % n] = x;
        } else if (t == 2) {
            int p;
            cin >> p;
            cout << a[(p - 1 + r) % n] << '\n';
        } else {
            int k;
            cin >> k;
            r = (r + k) % n;
        }
    }
}