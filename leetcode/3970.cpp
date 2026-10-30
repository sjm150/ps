typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;
const int inf = 1e9;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pi>> es(n);
        for (auto &e: edges) es[e[0]].emplace_back(e[2], e[1]);

        vector<vector<int>> dst(n, vector<int>(k, inf));
        priority_queue<ti, vector<ti>, greater<ti>> pq;
        dst[0][0] = 0;
        pq.emplace(0, 0, 0);
        while (!pq.empty()) {
            auto [d, cur, cnt] = pq.top();
            pq.pop();
            if (dst[cur][cnt] < d) continue;
            for (auto [w, nxt]: es[cur]) {
                int nc = labels[cur] == labels[nxt] ? cnt + 1 : 0;
                if (nc >= k) continue;
                if (dst[nxt][nc] > d + w) {
                    dst[nxt][nc] = d + w;
                    pq.emplace(d + w, nxt, nc);
                }
            }
        }

        int mn = *min_element(dst[n - 1].begin(), dst[n - 1].end());
        return mn < inf ? mn : -1;
    }
};