#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int mina = k - 1;
        int evn = 0, odd = 0;
        while (n--) {
            int a; cin >> a;
            if (a % 2) odd++;
            else evn++;
            mina = min(mina, (k - (a % k)) % k);
        }
        if (k == 4) {
            if (evn >= 2) mina = 0;
            else if (evn == 1 && odd >= 1) mina = min(mina, 1);
            else if (odd >= 2) mina = min(mina, 2);
        }
        cout << mina << '\n';
    }
}