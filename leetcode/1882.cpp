typedef long long ll;
typedef tuple<int, int, ll> ti;
typedef pair<ll, int> pi;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        vector<int> ans(m);
        priority_queue<ti, vector<ti>, greater<ti>> fs;
        priority_queue<pi, vector<pi>, greater<pi>> ws;
        for (int i = 0; i < n; i++) fs.emplace(servers[i], i, 0);
        for (int j = 0; j < m; j++) {
            while (!ws.empty() && ws.top().first <= j) {
                auto [t, i] = ws.top();
                ws.pop();
                fs.emplace(servers[i], i, t);
            }
            if (fs.empty()) {
                int t = ws.top().first;
                while (!ws.empty() && ws.top().first <= t) {
                    auto [_, i] = ws.top();
                    ws.pop();
                    fs.emplace(servers[i], i, t);
                }
            }
            auto [_, i, t] = fs.top();
            fs.pop();
            ans[j] = i;
            ws.emplace(max(ll(j), t) + tasks[j], i);
        }
        return ans;
    }
};