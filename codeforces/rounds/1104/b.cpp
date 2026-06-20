#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &a: a) cin >> a;
        for (int &b: b) cin >> b;
        auto solve = [&]() {
           int cnt = 0;
            for (int i = 0; i < n; i++) {
                int j = i;
                while (j < n && a[j] > b[i]) j++;
                if (j == n) return -1;
                for (int k = j - 1; k >= i; k--) {
                    swap(a[k], a[k + 1]);
                    cnt++;
                }
            }
            return cnt;
        };
        cout << solve() << '\n';
    }
}