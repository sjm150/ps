#include <bits/stdc++.h>
using namespace std;

const int mx = 81;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        auto sum = [](int x) {
            int ret = 0;
            for (; x; x /= 10) ret += x % 10;
            return ret;
        };
        int ans = -1;
        for (int i = (n + 10) / 10 * 10 - n; i <= mx; i += 10) {
            if (sum(n + i) == i) {
                ans = n + i;
                break;
            }
        }
        cout << ans << ' ';
    }
    cout << '\n';
}