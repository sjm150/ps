#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x, y; cin >> n >> x >> y;
        x--, y--;
        vector<int> a(n, 0);
        a[x] = 0, a[y] = 1;
        int cur = 0, cnt = 0;
        for (int i = (y + 1) % n; i != x; i = (i + 1) % n) {
            a[i] = cur;
            cur = 1 - cur;
            cnt++;
        }
        if (cnt % 2) a[(x - 1 + n) % n] = 2;
        cur = 0, cnt = 0;
        for (int i = (y - 1 + n) % n; i != x; i = (i - 1 + n) % n) {
            a[i] = cur;
            cur = 1 - cur;
            cnt++;
        }
        if (cnt % 2) a[(x + 1) % n] = 2;
        for (int a: a) cout << a << ' ';
        cout << '\n';
    }
}