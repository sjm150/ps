#include <bits/stdc++.h>
using namespace std;
const int inf = 2 * 1e9;
typedef pair<int, int> pi;

typedef struct SegTree {
    int n;
    vector<pi> val;

    SegTree(vector<int>& input) {
        n = input.size();
        val = vector<pi>(4 * n);
        init(input, 0, n - 1, 0);
    }
    pi init(vector<int>& input, int l, int r, int node) {
        if (l == r) return val[node] = {input[l], input[l]};
        int m = (l + r) / 2;
        pi lval = init(input, l, m, node * 2 + 1);
        pi rval = init(input, m + 1, r, node * 2 + 2);
        return val[node] = {min(lval.first, rval.first), max(lval.second, rval.second)};
    }

    pi query(int ql, int qr, int l, int r, int node) {
        if (r < ql || qr < l) return {inf, -inf};
        if (ql <= l && r <= qr) return val[node];
        int m = (l + r) / 2;
        pi lval = query(ql, qr, l, m, node * 2 + 1);
        pi rval = query(ql, qr, m + 1, r, node * 2 + 2);
        return {min(lval.first, rval.first), max(lval.second, rval.second)};
    }
    pi query(int l, int r) {
        return query(l - 1, r - 1, 0, n - 1, 0);
    }
} st_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> input(n);
    for (int i = 0; i < n; i++) cin >> input[i];
    st_t st(input);
    while (m--) {
        int a, b; cin >> a >> b;
        pi res = st.query(a, b);
        cout << res.first << ' ' << res.second << '\n';
    }
}