#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        deque<int> o, z;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') o.push_back(i);
            else z.push_back(i);
        }
        ll ans = n * ll(n + 1) / 2;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                if (!o.empty() && o.back() == i) o.pop_back();
                else continue;
                if (!z.empty()) {
                    ans -= i + 1;
                    z.pop_back();
                } else if (!o.empty()) {
                    ans -= i + 1;
                    o.pop_front();
                }
            } else {
                if (!z.empty() && z.back() == i) z.pop_back();
            }
        }
        cout << ans << '\n';
    }
}