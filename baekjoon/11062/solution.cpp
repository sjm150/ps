#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        vector<vector<int>> s(n, vector<int>(n));
        for (int i = 0; i < n; i++) s[i][i] = a[i];
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i + l - 1 < n; i++) s[i][i + l - 1] = max(a[i] - s[i + 1][i + l - 1], a[i + l - 1] - s[i][i + l - 2]);
        }
        cout << (s[0][n - 1] + accumulate(a.begin(), a.end(), 0)) / 2 << '\n';
    }
}