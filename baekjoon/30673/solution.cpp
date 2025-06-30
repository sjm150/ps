#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> pref(c + 1, 0);
        while (n--) {
            int a;
            cin >> a;
            pref[a]++;
        }
        for (int i = 1; i <= c; i++) pref[i] += pref[i - 1];
        
        auto solve = [&]() {
            for (int i = 1; i <= c; i++) {
                if (pref[i] > pref[i - 1]) continue;
                for (int j = 1; i * j <= c; j++) {
                    if (pref[j] == pref[j - 1]) continue;
                    int l = i * j, r = min(c, (i + 1) * j - 1);
                    if (pref[r] > pref[l - 1]) return false;
                }
            }
            return true;
        };

        cout << (solve() ? "Yes\n" : "No\n");
    }
}