typedef pair<int, int> pi;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> s;
        for (int i = 0; i < k; i++) s.insert(i);
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        vector<int> cnt(k, 0);
        int n = arrival.size();

        for (int i = 0; i < n; i++) {
            while (!pq.empty() && pq.top().first <= arrival[i]) {
                s.insert(pq.top().second);
                pq.pop();
            }
            if (s.empty()) continue;
            auto it = s.lower_bound(i % k);
            if (it == s.end()) it = s.begin();
            cnt[*it]++;
            pq.emplace(arrival[i] + load[i], *it);
            s.erase(it);
        }

        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (cnt[i] == mx) ans.push_back(i);
        }
        return ans;
    }
};