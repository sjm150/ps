#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int inf = 1e9;
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        int emx = 0, emn = inf, omx = 0, omn = inf;
        for (int a: a) {
            if (a % 2) {
                omx = max(omx, a);
                omn = min(omn, a);
            } else {
                emx = max(emx, a);
                emn = min(emn, a);
            }
        }

        auto chk = [&]() {
            int mx = 0;
            for (int a: a) {
                if (a % 2 == 0) continue;
                if (mx <= a) {
                    mx = a;
                } else {
                    if (a < emn && emx < mx) return false;
                }
            }

            mx = 0;
            for (int a: a) {
                if (a % 2 == 1) continue;
                if (mx <= a) {
                    mx = a;
                } else {
                    if (a < omn && omx < mx) return false;
                }
            }

            return true;
        };

        cout << (chk() ? "YES\n" : "NO\n");
    }
}