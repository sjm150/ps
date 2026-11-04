typedef long long ll;
const int inf = 1e9;
const ll linf = 1e18;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        multiset<int> lo = {-inf}, hi = {inf};
        ll lsum = 0, hsum = 0;
        auto push = [&](int a) {
            if (*prev(lo.end()) < a) {
                hsum += a;
                hi.insert(a);
                if (lo.size() < hi.size()) {
                    auto it = hi.begin();
                    lsum += *it;
                    hsum -= *it;
                    lo.insert(*it);
                    hi.erase(it);
                }
            } else {
                lsum += a;
                lo.insert(a);
                if (lo.size() > hi.size() + 1) {
                    auto it = prev(lo.end());
                    hsum += *it;
                    lsum -= *it;
                    hi.insert(*it);
                    lo.erase(it);
                }
            }
        };
        auto pop = [&](int a) {
            if (*prev(lo.end()) < a) {
                hsum -= a;
                hi.erase(hi.find(a));
                if (lo.size() > hi.size() + 1) {
                    auto it = prev(lo.end());
                    hsum += *it;
                    lsum -= *it;
                    hi.insert(*it);
                    lo.erase(it);
                }
            } else {
                lsum -= a;
                lo.erase(lo.find(a));
                if (lo.size() < hi.size()) {
                    auto it = hi.begin();
                    lsum += *it;
                    hsum -= *it;
                    lo.insert(*it);
                    hi.erase(it);
                }
            }
        };

        vector<vector<ll>> mn(n + 1, vector<ll>(k + 1, linf));
        for (int i = 0; i <= n; i++) mn[i][0] = 0;

        for (int i = 1; i < x; i++) push(nums[i - 1]);
        for (int i = x; i <= n; i++) {
            push(nums[i - 1]);
            ll cur = ll(lo.size() - hi.size()) * *prev(lo.end()) - lsum + hsum;
            for (int j = 1; j <= k; j++) mn[i][j] = min(mn[i - 1][j], mn[i - x][j - 1] + cur);
            pop(nums[i - x]);
        }

        return mn[n][k];
    }
};