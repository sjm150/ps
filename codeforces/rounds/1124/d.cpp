#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        int c3 = 0, c5 = 0;
        for (int a: a) {
            if (a % 3 == 0) c3++;
            else if (a % 5 == 0) c5++;
        }
        cout << c3 + c5 << ' ';
        while (q--) {
            int p, x;
            cin >> p >> x;
            p--;
            if (a[p] % 3 == 0) c3--;
            else if (a[p] % 5 == 0) c5--;
            a[p] = x;
            if (a[p] % 3 == 0) c3++;
            else if (a[p] % 5 == 0) c5++;
            cout << c3 + c5 << ' ';
        }
        cout << '\n';
    }
}