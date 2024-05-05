#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int l = 0, r = 1;
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == s[i]) tie(l, r) = pi(min(i, 2 * i - r), 2 * i - l);
        }
        cout << max(r, n) - l << '\n';
    }
}