#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int mx = 0;
    long long sum = 0;
    while (n--) {
        int k; cin >> k;
        if (mx < k) {
            sum += mx;
            mx = k;
        } else {
            sum += k;
        }
    }

    if (sum <= mx) cout << sum << '\n';
    else cout << (sum + mx) / 2 << '\n';
}