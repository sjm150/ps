#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int w, l; cin >> w >> l;

        function<int(int, int)> gcd = [&](int a, int b) {
            if (b == 0) return a;
            return gcd(b, a % b);
        };
        int g[] = {gcd(w - 1, l - 1), gcd(w - 2, l), gcd(w, l - 2), gcd(w, gcd(w - 2, l - 1)), gcd(l, gcd(l - 2, w - 1)), gcd(gcd(w, w - 1), gcd(l - 1, l - 2)), gcd(gcd(w - 1, w - 2), gcd(l, l - 1))};

        set<int> ans;
        for (int g: g) {
            for (int j = 1; j * j <= g; j++) {
                if (g % j) continue;
                ans.insert(j);
                ans.insert(g / j);
            }
        }

        cout << ans.size();
        for (int a: ans) cout << ' ' << a;
        cout << '\n';
    }
}