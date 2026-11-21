class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> edges(n);
        for (int i = 1; i < n; i++) edges[parent[i]].push_back(i);

        vector<int> sz(n, 1);
        vector<vector<int>> lst(26);
        function<void(int, int)> dfs = [&](int pre, int cur) {
            lst[s[cur] - 'a'].push_back(cur);
            for (int nxt: edges[cur]) dfs(cur, nxt);
            lst[s[cur] - 'a'].pop_back();
            if (pre < 0) return;
            if (lst[s[cur] - 'a'].empty()) sz[pre] += sz[cur];
            else sz[lst[s[cur] - 'a'].back()] += sz[cur];
        };
        dfs(-1, 0);

        return sz;
    }
};