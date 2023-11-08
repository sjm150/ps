#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        sort(b.begin(), b.end(), greater<int>());

        int j = 0;
        for (int i = 0; i < n; i++) {
            for (; j < m && b[j] >= a[i]; j++) cout << b[j] << ' ';
            cout << a[i] << ' ';
        }
        for (; j < m; j++) cout << b[j] << ' ';
        cout << '\n';
    }
}