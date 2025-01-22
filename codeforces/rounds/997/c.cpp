#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        a[0] = 1;
        int cur = 1;
        for (int i = 1; i < n; i++) {
            a[i] = cur++;
            if (cur > n / 2) cur = 1;
        }
        for (int a: a) cout << a << ' ';
        cout << '\n';
    }
}