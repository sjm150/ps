#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
 
        int ans = n;
        int pre = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                ans--;
                pre = -1;
            } else if (a[i] > 4) {
                pre = -1;
            } else if (a[i] <= 2) {
                if (pre >= 0 && (i - pre + 1) % 2 == 0) {
                    ans--;
                    pre = -1;
                } else {
                    pre = i;
                }
            }
        }

        cout << ans << '\n';
    }
}