#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    vector<bool> ok(n, false);
    ok[0] = true;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (ok[j] && (abs(a[i] - a[j]) + 1) * (i - j) <= k) {
                ok[i] = true;
                break;
            }
        }
    }
    cout << (ok[n - 1] ? "YES\n" : "NO\n");
}