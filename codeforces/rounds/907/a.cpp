#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        bool poss = true;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i + 1] && (i & (i - 1))) {
                poss = false;
                break;
            }
        }
        if (poss) cout << "YES\n";
        else cout << "NO\n";
    }
}