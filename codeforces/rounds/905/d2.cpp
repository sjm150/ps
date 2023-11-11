#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int a[100000], b[100000], c[100000];

int cntop(int m) {
    int ai = 0, ci = 0;
    while (ai < n - 1 && a[ai] < m) c[ci++] = a[ai++];
    c[ci++] = m;
    while (ai < n - 1) c[ci++] = a[ai++];

    int l = 0, r = n + 1;
    while (l < r) {
        int len = (l + r) / 2;
        bool poss = true;
        for (int i = 0; i < len; i++) {
            if (!(poss = (c[i] < b[n - len + i]))) break;
        }
        if (poss) l = len + 1;
        else r = len;
    }
    return n - r + 1;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n - 1; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        sort(a, a + n - 1);
        sort(b, b + n);

        ll tot = 0;
        int i = 1, cnt = cntop(1);
        while (i <= m) {
            int l = i + 1, r = m + 2;
            while (l < r) {
                int m = (l + r) / 2;
                int cur = cntop(m);
                if (cur <= cnt) l = m + 1;
                else r = m;
            }
            tot += ll(min(r, m + 1) - i) * cnt;
            i = r;
            cnt++;
        }

        cout << tot << '\n';
    }
}