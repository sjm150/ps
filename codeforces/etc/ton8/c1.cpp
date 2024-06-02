#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x, y; cin >> n >> x >> y;
        vector<int> b(x);
        for (int &b: b) cin >> b;
        sort(b.begin(), b.end());

        int cnt = n - 2;
        if (b[0] + n - b[x - 1] > 2) cnt -= b[0] + n - b[x - 1] - 1;
        for (int i = 1; i < x; i++) {
            if (b[i] - b[i - 1] > 2) cnt -= b[i] - b[i - 1] - 1;
        }

        cout << cnt << '\n';
    }
}