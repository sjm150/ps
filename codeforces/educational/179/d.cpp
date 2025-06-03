#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int &a: a) cin >> a;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            int x = a[i / 2], y = a[m - 1 - i / 2];
            if (i % 2) swap(x, y);
            for (int j = 0; j < 3; j++) cout << x << ' ' << y << ' ';
            cout << '\n';
        }
    }
}