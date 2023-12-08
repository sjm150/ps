#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i) continue;
        k--;
        if (k == 0) {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
}