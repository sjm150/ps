typedef long long ll;
typedef pair<int, int> pi;

class Solution {
public:
    ll countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        ll cnt = 0, ans = 0;
        priority_queue<pi> pq;
        vector<int> stk, nxt(n, n);
        vector<vector<int>> cov(n);

        for (int l = 0, r = 0; r < n; r++) {
            if (!pq.empty() && nums[r] < pq.top().first) cnt += pq.top().first - nums[r];
            pq.emplace(nums[r], r);

            while (!stk.empty() && nums[stk.back()] <= nums[r]) {
                nxt[stk.back()] = r;
                stk.pop_back();
            }
            if (!stk.empty()) cov[stk.back()].push_back(r);
            stk.push_back(r);

            while (k < cnt) {
                for (int i: cov[l]) cnt -= ll(nums[l] - nums[i]) * (min(r + 1, nxt[i]) - i);
                l++;
            }
            while (!pq.empty() && pq.top().second < l) pq.pop();

            ans += r - l + 1;
        }

        return ans;
    }
};