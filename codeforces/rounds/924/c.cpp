#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        if ((n + x) & 1) {
            cout << 0 << '\n';
            continue;
        }

        set<int> k;
        int d = (n - x) / 2;
        for (int i = 1; i * i <= d; i++) {
            if (d % i == 0) {
                if (i + 1 >= x) k.insert(i + 1);
                if (d / i + 1 >= x) k.insert(d / i + 1);
            }
        }
        d = (n + x - 2) / 2;
        for (int i = 1; i * i <= d; i++) {
            if (d % i == 0) {
                if (i + 1 >= x) k.insert(i + 1);
                if (d / i + 1 >= x) k.insert(d / i + 1);
            }
        }

        cout << k.size() << '\n';
    }
}