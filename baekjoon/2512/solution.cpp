#include <bits/stdc++.h>
using namespace std;

int req[10000];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n;
    int l = 1, r = 0;
    for (int i = 0; i < n; i++) {
        cin >> req[i];
        r = max(r, req[i]);
    }
    r++;
    cin >> m;
    while (l < r) {
        int mid = (l + r) / 2;
        int sum = 0;
        for (int i = 0; i < n; i++) sum += min(req[i], mid);
        if (sum <= m) l = mid + 1;
        else r = mid;
    }
    cout << r - 1 << '\n';
}