#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        bool same = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != a[0]) {
                same = false;
                break;
            }
        }
        if (same) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            vector<int> ans(n, 1);
            ans[max_element(a.begin(), a.end()) - a.begin()] = 2;
            for (int a: ans) cout << a << ' ';
            cout << '\n';
        }
    }
}