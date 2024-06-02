#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
 
        bool poss = true;
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > a[i + 1]) {
                if (a[i] % 10 <= a[i + 1] && a[i] / 10 <= a[i] % 10) {
                    a[i] /= 10;
                } else {
                    poss = false;
                    break;
                }
            }
        }
 
        if (poss) cout << "YES\n";
        else cout << "NO\n";
    }
}
