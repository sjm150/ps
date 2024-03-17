#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> cnt(n + 1, 0);
        for (int a: a) cnt[a]++;

        bool f = true;
        for (int i = 0; i <= n; i++) {
            if (cnt[i] == 0) {
                cout << i << '\n';
                break;
            } else if (cnt[i] == 1) {
                if (f) {
                    f = false;
                } else {
                    cout << i << '\n';
                    break;
                }
            }
        }
    }
}