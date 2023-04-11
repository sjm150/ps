#include <iostream>
#include <vector>

using namespace std;

void preorder(const vector<vector<int>>& edges, vector<int>& order, int curr, int depth);

vector<int> idx;
vector<int> priority;

typedef struct SegTree {
    int n;
    vector<int> range_value;

    SegTree(const vector<int>& arr) {
        n = arr.size();
        range_value = vector<int>(4 * n);
        init(arr, 0, 0, n - 1);
    }

    int init(const vector<int>& arr, int node, int l, int r) {
        if (l == r) return range_value[node] = arr[l];
        int mid = (l + r) / 2;
        int lval = init(arr, 2 * node + 1, l, mid);
        int rval = init(arr, 2 * node + 2, mid + 1, r);
        
        if (priority[lval] < priority[rval]) range_value[node] = lval;
        else range_value[node] = rval;

        return range_value[node];
    }

    int query(int l, int r, int curr, int lcurr, int rcurr) {
        if (rcurr < l || r < lcurr) return -1;
        if (l <= lcurr && rcurr <= r) return range_value[curr];

        int mid = (lcurr + rcurr) / 2;
        int lval = query(l, r, 2 * curr + 1, lcurr, mid);
        int rval = query(l, r, 2 * curr + 2, mid + 1, rcurr);

        if (lval < 0) return rval;
        else if (rval < 0) return lval;
        else if (priority[lval] < priority[rval]) return lval;
        else return rval;
    }

    int query(int l, int r) {
        int lca = query(min(idx[l], idx[r]), max(idx[l], idx[r]), 0, 0, n - 1);
        return priority[l] + priority[r] - 2 * priority[lca];
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
        vector<vector<int>> childs(n);
        for (int i = 1; i < n; i++) {
            int parent;
            cin >> parent;
            childs[parent].push_back(i);
        }

        vector<int> order;
        idx = priority = vector<int>(n);
        preorder(childs, order, 0, 0);
        segtree_t st(order);

        for (int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;
            cout << st.query(a, b) << '\n';
        }
    }
}

void preorder(const vector<vector<int>>& edges, vector<int>& order, int curr, int depth) {
    idx[curr] = order.size();
    order.push_back(curr);
    priority[curr] = depth;
    for (int next: edges[curr]) {
        preorder(edges, order, next, depth + 1);
        order.push_back(curr);
    }
}