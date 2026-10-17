typedef long long ll;

typedef struct Segtree {
    int sz = 1;
    vector<ll> val, lz;
    Segtree(int n) {
        while (sz < n) sz *= 2;
        val = lz = vector<ll>(sz * 2, 0);
    }

    void prop(int nd, int nl, int nr) {
        if (lz[nd] == 0) return;
        if (nd < sz) {
            lz[nd * 2] += lz[nd];
            lz[nd * 2 + 1] += lz[nd];
        }
        val[nd] += lz[nd] * (nr - nl + 1);
        lz[nd] = 0;
    }

    void add(int l, int r, int x, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (nr < l || r < nl) return;
        if (l <= nl && nr <= r) {
            lz[nd] += x;
            prop(nd, nl, nr);
            return;
        }
        int m = (nl + nr) / 2;
        add(l, r, x, nd * 2, nl, m);
        add(l, r, x, nd * 2 + 1, m + 1, nr);
        val[nd] = val[nd * 2] + val[nd * 2 + 1];
    }
    void add(int l, int r, int x) { add(l, r, x, 1, 0, sz - 1); }

    ll query(int l, int r, int nd, int nl, int nr) {
        prop(nd, nl, nr);
        if (nr < l || r < nl) return 0;
        if (l <= nl && nr <= r) return val[nd];
        int m = (nl + nr) / 2;
        return query(l, r, nd * 2, nl, m) + query(l, r, nd * 2 + 1, m + 1, nr);
    }
    ll query(int l, int r) { return query(l, r, 1, 0, sz - 1); }
} st_t;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const ll mod = 1e9 + 7;
        int n = nums.size();
        Segtree st(n);
        unordered_map<int, int> lst;
        ll sum = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            auto it = lst.find(nums[i]);
            int j = it == lst.end() ? 0 : it->second + 1;
            cur = (cur + 2 * st.query(j, i) + i - j + 1) % mod;
            sum = (sum + cur) % mod;
            st.add(j, i, 1);
            lst[nums[i]] = i;
        }
        return sum;
    }
};