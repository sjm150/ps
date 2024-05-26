#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        int cnt = a[n - 1] > a[0];
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) cnt++;
        }
        cout << (cnt <= 1 ? "YES\n" : "NO\n");
    }
}