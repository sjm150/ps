#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<bool> vst(n, false);
        bool poss = true;
        int lst = n - 1;
        vst[lst] = true;
        while (k--) {
            if (b[lst] > n) {
                poss = false;
                break;
            }
            lst = (lst + n - b[lst]) % n;
            if (vst[lst]) break;
            vst[lst] = true;
        }

        if (poss) cout << "YES\n";
        else cout << "NO\n";
    }
}