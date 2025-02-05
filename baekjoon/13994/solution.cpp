#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long double ld;
    string s; cin >> s;
    int n = s.size();
    ld c = 0, w = 0, ans = 0;
    (s[0] == 'C' ? c : w) = 1.l / n;
    for (int i = 1; i < n; i++) {
        if (s[i] == 'C') {
            c += 1.l / (n - i) / (n - i + 1);
            ans += w * (n - i);
        } else {
            w += 1.l / (n - i) / (n - i + 1);
            ans += c * (n - i);
        }
    }
    cout << setprecision(10) << ans << '\n';
}