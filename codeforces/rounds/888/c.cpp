#include <iostream>
using namespace std;

int c[200000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> c[i];
        if (c[0] == c[n - 1]) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (c[i] == c[0]) cnt++;
            }
            if (cnt >= k) cout << "YES\n";
            else cout << "NO\n";
        } else {
            int cnt = 0;
            int i = 0;
            for (; i < n; i++) {
                if (c[i] == c[0]) cnt++;
                if (cnt == k) break;
            }
            if (cnt < k) {
                cout << "NO\n";
                continue;
            }
            cnt = 0;
            for (; i < n; i++) {
                if (c[i] == c[n - 1]) cnt++;
            }
            if (cnt >= k) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}