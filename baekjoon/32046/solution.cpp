#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (;;) {
        int n;
        cin >> n;
        if (!n) break;
        int ans = 0;
        while (n--) {
            int a;
            cin >> a;
            if (ans + a <= 300) ans += a;
        }
        cout << ans << '\n';
    }
}