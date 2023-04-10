#include <iostream>
#include <vector>

using namespace std;

typedef struct SegTree {
    int n;
    vector<int> range_value;

    SegTree(const vector<int>& arr) {
        n = arr.size();
        range_value = vector<int>(n * 4);
        init(arr, 0, n - 1, 0);
    }

    int init(const vector<int>& arr, int l, int r, int node) {
        if (l == r) return range_value[node] = arr[l];
        int mid = (l + r) / 2;
        int lmin = init(arr, l, mid, 2 * node + 1);
        int rmin = init(arr, mid + 1, r, 2 * node + 2);
        return range_value[node] = min(lmin, rmin);
    }

    int query(int l, int r, int node, int lnode, int rnode) {
        if (r < lnode || rnode < l) return INT32_MAX;
        if (l <= lnode && rnode <= r) return range_value[node];
        int mid = (lnode + rnode) / 2;
        int lmin = query(l, r, 2 * node + 1, lnode, mid);
        int rmin = query(l, r, 2 * node + 2, mid + 1, rnode);
        return min(lmin, rmin);
    }

    int get_range_val(int l, int r) {
        return query(l, r, 0, 0, n - 1);
    }
} segtree_t;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        int n, q;
        cin >> n >> q;
        vector<int> heights(n);
        for (int i = 0; i < n; i++) cin >> heights[i];
        vector<int> mheights(n);
        for (int i = 0; i < n; i++) mheights[i] = -heights[i];

        segtree_t mintree(heights);
        segtree_t maxtree(mheights);

        for (int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;
            cout << - (mintree.get_range_val(a, b) + maxtree.get_range_val(a, b)) << '\n';
        }
    }
}