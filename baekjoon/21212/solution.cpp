#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int ans = 1e9;
    while (n--) {
        int a, b; cin >> a >> b;
        ans = min(ans, b / a);
    }
    cout << ans << '\n';
}