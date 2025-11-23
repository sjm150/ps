#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        x--;
        string s;
        cin >> s;

        auto solve = [&]() {
            int l = x - 1, r = x + 1;
            while (0 <= l && s[l] == '.') l--;
            while (r < n && s[r] == '.') r++;

            if (l == -1 && r == n) return 1;
            if (l == x - 1 || r == x + 1) return min(x + 1, n - x);

            return min(max(l + 2, n + 1 - r), min(x + 1, n - x));
        };

        cout << solve() << '\n';
    }
}