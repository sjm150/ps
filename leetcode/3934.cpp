typedef long long ll;
const ll mod = 1e9 + 7;
const ll base = 23426;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<ll> h(n + 1), p(n + 1);
        p[0] = 1;
        for (int i = 0; i < n; i++) {
            h[i + 1] = (h[i] * base + nums[i]) % mod;
            p[i + 1] = p[i] * base % mod;
        }

        auto chk = [&](int len) {
            unordered_map<ll, int> cnt;
            for (int i = 0; i + len <= n; i++) cnt[(h[i + len] - h[i] * p[len] % mod + mod) % mod]++;
            for (auto [_, c]: cnt) {
                if (c == 1) return true;
            }
            return false;
        };

        int l = 1, r = n + 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (chk(m)) r = m;
            else l = m + 1;
        }
        return r;
    }
};