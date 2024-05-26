#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        vector<int> k(n);
        for (int &k: k) cin >> k;

        int xk = 0;
        for (int k: k) xk ^= k;
        int msb = 1 << 30;
        for (; msb; msb >>= 1) {
            if (xk & msb) break;
        }

        int cnt = 0;
        for (int k: k) {
            if (msb & k) cnt++;
        }
        cout << cnt << '\n';
    }
}