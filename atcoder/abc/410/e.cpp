#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, h, m;
    cin >> n >> h >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    int l = 0, r = n;
    while (l < r) {
        int md = (l + r) / 2;
        vector<int> mx(h + 1, 0);
        for (int i = 0; i <= md; i++) {
            for (int j = h; j >= a[i]; j--) mx[j] = max(mx[j], mx[j - a[i]] + b[i]);
        }
        if (accumulate(b.begin(), b.begin() + md + 1, 0) - *max_element(mx.begin(), mx.end()) <= m) l = md + 1;
        else r = md;
    }
    cout << r << '\n';
}