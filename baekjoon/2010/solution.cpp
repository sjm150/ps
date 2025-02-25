#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int ans = 1;
    while (n--) {
        int x; cin >> x;
        ans += x - 1;
    }
    cout << ans << '\n';
}