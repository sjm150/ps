#include <bits/stdc++.h>
using namespace std;

int a[100];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int mina = 1e9 + 1, cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (mina > a[i]) {
                mina = a[i];
                cnt = 1;
            } else if (mina == a[i]) {
                cnt++;
            }
        }
        if (cnt != 0 && cnt != n) {
            cout << cnt << ' ' << n - cnt << '\n';
            while (cnt--) cout << mina << ' ';
            cout << '\n';
            for (int i = 0; i < n; i++) {
                if (a[i] != mina) cout << a[i] << ' ';
            }
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}