class SparseTable {
    int n, sz;
    vector<vector<pair<int, int>>> val;
public:
    SparseTable(vector<pair<int, int>> &a) {
        n = a.size();
        sz = log2(n) + 1;
        val.resize(sz);
        val[0] = a;
        for (int i = 1; i < sz; i++) {
            val[i].resize(n);
            for (int j = 0; j + (1 << i) <= n; j++) val[i][j] = min(val[i - 1][j], val[i - 1][j + (1 << (i - 1))]);
        }
    }
    pair<int, int> query(int l, int r) {
        int i = log2(r - l + 1);
        return min(val[i][l], val[i][r - (1 << i) + 1]);
    }
};

class Fwtree {
    vector<int> val;
    void addx(int i, int v) {
        i++;
        while (i < val.size()) {
            val[i] ^= v;
            i += i & -i;
        }
    }
public:
    Fwtree(int n): val(n + 1, 0) {}
    int get(int i) {
        i++;
        int ret = 0;
        while (i) {
            ret ^= val[i];
            i &= i - 1;
        }
        return ret;
    }
    void addx(int l, int r, int v) {
        addx(l, v);
        addx(r + 1, v);
    }
};

class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> tree(n);
        for (auto &e: edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        int sz = 0, psz = 0;
        vector<int> in(n), out(n), h(n), pth(n * 2);
        function<void(int, int)> dfs = [&](int pre, int cur) {
            pth[psz++] = cur;
            in[cur] = sz++;
            for (int nxt: tree[cur]) {
                if (pre != nxt) {
                    h[nxt] = h[cur] + 1;
                    dfs(cur, nxt);
                    pth[psz++] = cur;
                }
            }
            out[cur] = sz++;
        };
        h[0] = 0;
        dfs(-1, 0);

        vector<pair<int, int>> hp(psz);
        for (int i = 0; i < psz; i++) hp[i] = make_pair(h[pth[i]], pth[i]);
        SparseTable st(hp);
        auto lca = [&](int u, int v) {
            if (in[u] > in[v]) swap(u, v);
            return st.query(in[u], in[v]).second;
        };

        auto bm = [&](char c) { return 1 << (c - 'a'); };
        auto pal = [&](int x) { return __builtin_popcount(x) < 2; };

        Fwtree fwt(sz);
        for (int i = 0; i < n; i++) fwt.addx(in[i], out[i], bm(s[i]));

        vector<bool> ans;
        for (auto &q: queries) {
            istringstream iss(q);
            string cmd;
            iss >> cmd;
            if (cmd[0] == 'q') {
                int u, v;
                iss >> u >> v;
                ans.push_back(pal(fwt.get(in[u]) ^ fwt.get(in[v]) ^ bm(s[lca(u, v)])));
            } else {
                int u;
                char c;
                iss >> u >> c;
                fwt.addx(in[u], out[u], bm(s[u]));
                s[u] = c;
                fwt.addx(in[u], out[u], bm(s[u]));
            }
        }

        return ans;
    }
};