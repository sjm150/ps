#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }
    string ans;
    for (; n; n /= 3) {
        int r = (n % 3 + 3) % 3;
        if (r == 0) {
            ans += '0';
        } else if (r == 1) {
            ans += '1';
            n--;
        } else {
            ans += 'T';
            n++;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}