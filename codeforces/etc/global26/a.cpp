#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        int idx = -1;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] != a[i]) {
                if (i == n - 1) idx = i - 1;
                else idx = i;
            }
        }
        if (idx >= 0) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) cout << (i == idx ? 'R' : 'B');
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
}