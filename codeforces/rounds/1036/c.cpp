#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    function<int(int, int)> gcd = [&](int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    };
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int &b: b) cin >> b;
        int x = 1;
        for (int i = 0; i < n - 1; i++) {
            if (b[i + 1] % b[i]) {
                int f = b[i] / gcd(b[i], b[i + 1]);
                x *= f / gcd(x, f);
            }
        }
        cout << x << '\n';
    }
}