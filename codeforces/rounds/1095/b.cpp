#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int &p: p) cin >> p;
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (p[i] % abs(p[i + 1] - p[i]) == 0) cnt++;
        }
        cout << cnt << '\n';
    }
}