#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int a[2][500000];

ll merge(int l, int r, int cur) {
    if (l == r) return 0;
    int nxt = 1 - cur;
    int m = (l + r) / 2;
    ll cnt = merge(l, m, nxt) + merge(m + 1, r, nxt);
    int idx = l, li = l, ri = m + 1;
    while (li <= m && ri <= r) {
        if (a[nxt][li] <= a[nxt][ri]) {
            a[cur][idx++] = a[nxt][li++];
            cnt += idx - li;
        } else {
            a[cur][idx++] = a[nxt][ri++];
        }
    }
    while (li <= m) {
        a[cur][idx++] = a[nxt][li++];
        cnt += idx - li;
    }
    while (ri <= r) a[cur][idx++] = a[nxt][ri++];
    return cnt;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[0][i];
        a[1][i] = a[0][i];
    }
    cout << merge(0, n - 1, 0) << '\n';
}