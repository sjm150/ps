#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        int cur = 1, l = 0, r = n - 1;
        while (l <= r) {
            p[l++] = cur++;
            if (l <= r) p[r--] = cur++;
        }
        for (int p: p) cout << p << ' ';
        cout << '\n';
    }
}