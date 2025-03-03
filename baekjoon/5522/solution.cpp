#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        int a; cin >> a;
        ans += a;
    }
    cout << ans << '\n';
}