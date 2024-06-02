#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n + 1);
        for (int &a: a) cin >> a;
        for (int &b: b) cin >> b;

        int cpy = 1e9 + 5;
        ll ans = 1;
        for (int i = 0; i < n; i++) {
            ans += abs(a[i] - b[i]);
            if (b[n] < min(a[i], b[i])) cpy = min(cpy, min(a[i], b[i]) - b[n]);
            else if (b[n] > max(a[i], b[i])) cpy = min(cpy, b[n] - max(a[i], b[i]));
            else cpy = 0;
        }
        cout << ans + cpy << '\n';
    }
}