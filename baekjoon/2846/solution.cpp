#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for (int &p: p) cin >> p;
    int mn = p[0], ans = 0;
    for (int i = 1; i < n; i++) {
        if (p[i - 1] < p[i]) ans = max(ans, p[i] - mn);
        else mn = p[i];
    }
    cout << ans << '\n';
}