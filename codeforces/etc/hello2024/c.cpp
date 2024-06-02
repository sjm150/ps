#include <bits/stdc++.h>
using namespace std;
const int mx = 200000;
const int inf = 1e9;

int lis[mx];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }

        int pre[2], cnt = 0;
        pre[0] = inf + 1, pre[1] = inf;
        if (pre[0] < pre[1]) swap(pre[0], pre[1]);
        for (int i = 0; i < n; i++) {
            if (pre[0] < a[i]) {
                pre[1] = pre[0];
                pre[0] = a[i];
                cnt++;
            } else if (pre[1] < a[i]) {
                pre[0] = a[i];
            } else {
                pre[1] = a[i];
            }
        }

        cout << cnt << '\n';
    }
}