#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> x(n);
    for (int &x: x) cin >> x;
    int l = 0, r = accumulate(x.begin(), x.end(), 1);
    while (l < r) {
        int m = (l + r) / 2;
        int cur = 0, cnt = 0;
        for (int x: x) {
            cur += x;
            if (cur >= m) {
                cnt++;
                cur = 0;
            }
        }
        if (cnt >= k) l = m + 1;
        else r = m;
    }
    cout << r - 1 << '\n';
}