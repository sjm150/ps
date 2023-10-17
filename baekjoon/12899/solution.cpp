#include <bits/stdc++.h>
using namespace std;

const int mx = 2000001;
int val[4200000];

int add(int i, int l, int r, int node) {
    if (i < l || r < i) return val[node];
    if (l == r) return val[node] += 1;
    int m = (l + r) / 2;
    int lval = add(i, l, m, 2 * node + 1);
    int rval = add(i, m + 1, r, 2 * node + 2);
    return val[node] = lval + rval;
}
void add(int i) {
    add(i, 0, mx - 1, 0);
}

int query(int i, int l, int r, int node) {
    val[node]--;
    if (l == r) return l;
    int m = (l + r) / 2;
    int lval = val[2 * node + 1];
    if (i <= lval) return query(i, l, m, 2 * node + 1);
    else return query(i - lval, m + 1, r, 2 * node + 2);
}
int query(int i) {
    return query(i, 0, mx - 1, 0);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    while (n--) {
        int t, x; cin >> t >> x;
        if (t == 1) add(x);
        else cout << query(x) << '\n';
    }
}