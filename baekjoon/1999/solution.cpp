#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, b, k;
    cin >> n >> b >> k;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &a: a) {
        for (int &a: a) cin >> a;
    }
    auto aa = a;

    multiset<int> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b - 1; j++) s.insert(a[i][j]);
        for (int j = 0; j + b - 1 < n; j++) {
            s.insert(a[i][j + b - 1]);
            int mn = *s.begin();
            s.erase(s.find(a[i][j]));
            a[i][j] = mn;
        }
        s.clear();
    }
    for (int j = 0; j + b - 1 < n; j++) {
        for (int i = 0; i < b - 1; i++) s.insert(a[i][j]);
        for (int i = 0; i + b - 1 < n; i++) {
            s.insert(a[i + b - 1][j]);
            int mn = *s.begin();
            s.erase(s.find(a[i][j]));
            a[i][j] = mn;
        }
        s.clear();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b - 1; j++) s.insert(aa[i][j]);
        for (int j = 0; j + b - 1 < n; j++) {
            s.insert(aa[i][j + b - 1]);
            int mx = *prev(s.end());
            s.erase(s.find(aa[i][j]));
            aa[i][j] = mx;
        }
        s.clear();
    }
    for (int j = 0; j + b - 1 < n; j++) {
        for (int i = 0; i < b - 1; i++) s.insert(aa[i][j]);
        for (int i = 0; i + b - 1 < n; i++) {
            s.insert(aa[i + b - 1][j]);
            int mx = *prev(s.end());
            s.erase(s.find(aa[i][j]));
            aa[i][j] = mx;
        }
        s.clear();
    }

    while (k--) {
        int i, j;
        cin >> i >> j;
        i--, j--;
        cout << aa[i][j] - a[i][j] << '\n';
    }
}