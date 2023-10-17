#include <bits/stdc++.h>
using namespace std;

int mx;
int val[270000];

int init(int l, int r, int node) {
    if (l == r) return val[node] = 1;
    int m = (l + r) / 2;
    int lval = init(l, m, 2 * node + 1);
    int rval = init(m + 1, r, 2 * node + 2);
    return val[node] = lval + rval;
}

int query(int k) {
    int l = 0, r = mx - 1, node = 0;
    while (l < r) {
        val[node]--;
        int m = (l + r) / 2;
        int lval = val[2 * node + 1];
        if (k <= lval) {
            r = m;
            node = 2 * node + 1;
        } else {
            l = m + 1;
            node = 2 * node + 2;
            k -= lval;
        }
    }
    val[node]--;
    return l;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int k; cin >> mx >> k;
    init(0, mx - 1, 0);
    int cur = k - 1;
    cout << "<";
    for (int n = mx; n > 1; n--) {
        cur = cur % n;
        cout << query(cur + 1) + 1 << ", ";
        cur += k - 1;
    }
    cout << query(1) + 1 << ">\n";
}