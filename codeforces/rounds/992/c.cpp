#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        long long k; cin >> k;
        k--;
        if (n == 1) {
            cout << (k ? -1 : 1) << '\n';
            continue;
        }
        deque<int> p;
        if (k % 2) {
            p.push_back(n--);
            p.push_back(n--);
        } else {
            p.push_front(n--);
            p.push_front(n--);
        }
        k /= 2;
        for (; n; n--, k /= 2) {
            if (k % 2) p.push_back(n);
            else p.push_front(n);
        }
        if (k) {
            cout << -1 << '\n';
        } else {
            for (int p: p) cout << p << ' ';
            cout << '\n';
        }
    }
}