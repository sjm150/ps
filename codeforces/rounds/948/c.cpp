#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        sort(a.begin(), a.end());

        bool dv = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[n - 1] % a[i]) {
                dv = false;
                break;
            }
        }
        if (!dv) {
            cout << n << '\n';
            continue;
        }

        function<int(int, int)> gcd = [&](int a, int b) {
            if (b == 0) return a;
            return gcd(b, a % b);
        };

        map<int, int> lcms;
        lcms[1] = 0;
        for (int a: a) {
            vector<pair<int, int>> res;
            for (auto [l, c]: lcms) {
                int g = gcd(a, l);
                if (g == a) res.emplace_back(l, c + 1);
                else res.emplace_back(l / g * a, c + 1);
            }
            for (auto [l, c]: res) lcms[l] = c;
        }

        int ans = 0;
        for (auto [l, c]: lcms) {
            if (!binary_search(a.begin(), a.end(), l)) ans = max(ans, c);
        }
        cout << ans << '\n';
    }
}