#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> lst(k + 1, -1);
    int l = -1, cnt = k, buf = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        if (c == 0) {
            buf += 2;
            continue;
        }
        bool ok = false;
        if (lst[c] <= l) {
            ok = true;
        } else if (buf >= cnt) {
            l = i - 1;
            cnt = k;
            buf = 0;
            ok = true;
        }
        if (ok) {
            lst[c] = i;
            cnt--;
            buf++;
            ans++;
        } else {
            buf += 2;
        }
    }
    cout << ans << '\n';
}