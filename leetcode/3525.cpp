typedef long long ll;

class Segtree {
    int k, sz;
    vector<int> prd;
    vector<vector<ll>> cnt;

    void merge(int nd) {
        prd[nd] = prd[nd * 2] * prd[nd * 2 + 1] % k;
        for (int i = 0; i < k; i++) cnt[nd][i] = cnt[nd * 2][i];
        for (int i = 0; i < k; i++) cnt[nd][prd[nd * 2] * i % k] += cnt[nd * 2 + 1][i];
    }

    void query(int nd, int nl, int nr, int l, int r, int &p, vector<ll> &res) {
        if (l <= nl && nr <= r) {
            for (int i = 0; i < k; i++) res[p * i % k] += cnt[nd][i];
            p = p * prd[nd] % k;
            return;
        }
        if (nr < l || r < nl) return;
        int m = (nl + nr) / 2;
        query(nd * 2, nl, m, l, r, p, res);
        query(nd * 2 + 1, m + 1, nr, l, r, p, res);
    }
public:
    Segtree(vector<int>& a, int k) {
        int n = a.size();
        this->k = k;
        sz = 1;
        while (sz < n) sz *= 2;
        prd.resize(sz * 2);
        cnt.resize(sz * 2, vector<ll>(k, 0));
        for (int i = 0; i < n; i++) cnt[i + sz][prd[i + sz] = a[i] % k]++;
        for (int i = sz - 1; i; i--) merge(i);
    }

    void update(int i, int x) {
        cnt[i + sz][prd[i + sz]]--;
        cnt[i + sz][prd[i + sz] = x % k]++;
        for (int j = (i + sz) / 2; j; j /= 2) merge(j);
    }

    ll query(int l, int r, int x) {
        vector<ll> res(k, 0);
        int p = 1;
        query(1, 0, sz - 1, l, r, p, res);
        return res[x];
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        Segtree st(nums, k);
        vector<int> res;
        for (auto &q: queries) {
            st.update(q[0], q[1]);
            res.push_back(st.query(q[2], n - 1, q[3]));
        }
        return res;
    }
};