#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        vector<int> n(k);
        for (int i = 0; i < k; i++) {
            cin >> n[i];
            int p;
            for (int j = 0; j < n[i] - 1; j++) cin >> p;
        }
        sort(n.begin(), n.end(), greater<int>());
        
        int ans = 0;
        for (int n: n) {
            for (int b = 1 << 20; b; b >>= 1) {
                if (b & n) {
                    if (ans & b) {
                        ans |= b - 1;
                        break;
                    } else {
                        ans |= b;
                    }
                }
            }
        }

        cout << ans << '\n';
    }
}