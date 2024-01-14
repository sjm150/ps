#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int p = 1;
        for (int k = 1; k < n; k++) {
            if (n % k) continue;
            int m = -1;
            for (int i = 0; i < k; i++) {
                int r = a[i];
                for (int j = i + k; j < n; j += k) {
                    int d = abs(a[j] - r);
                    if (d == 0) continue;
                    if (m < 0) m = d;
                    else m = gcd(m, d);
                    r %= m;
                    if (m == 1) break;
                }
                if (m == 1) break;
            }
            if (m != 1) p++;
        }

        cout << p << '\n';
    }
}