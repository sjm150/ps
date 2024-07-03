#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int fct[10];
    fct[0] = 1;
    for (int i = 1; i < 10; i++) fct[i] = fct[i - 1] * i;
    int y; cin >> y;
    if (y == 1) {
        cout << 0 << '\n';
        return 0;
    }
    string ans;
    for (int i = 9; i; i--) {
        while (y >= fct[i]) {
            y -= fct[i];
            ans += i + '0';
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}