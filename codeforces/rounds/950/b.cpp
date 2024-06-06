#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, f, k; cin >> n >> f >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        int v = a[f - 1];
        sort(a.begin(), a.end(), greater<int>());
        if (k == n || a[k] < v) cout << "YES\n";
        else if (a[k - 1] > v) cout << "NO\n";
        else cout << "MAYBE\n";
    }
}