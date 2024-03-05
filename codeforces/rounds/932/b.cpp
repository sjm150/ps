#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> lmex(n), rmex(n);
        int mex = 0;
        vector<bool> occ(n, false);
        for (int i = 0; i < n; i++) {
            occ[a[i]] = true;
            while (occ[mex]) mex++;
            lmex[i] = mex;
        }
        mex = 0;
        fill(occ.begin(), occ.end(), false);
        for (int i = n - 1; i >= 0; i--) {
            occ[a[i]] = true;
            while (occ[mex]) mex++;
            rmex[i] = mex;
        }

        bool poss = false;
        for (int i = 1; i < n; i++) {
            if (lmex[i - 1] == rmex[i]) {
                cout << 2 << '\n';
                cout << 1 << ' ' << i << '\n';
                cout << i + 1 << ' ' << n << '\n';
                poss = true;
                break;
            }
        }

        if (!poss) cout << -1 << '\n';
    }
}