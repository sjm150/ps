typedef long long ll;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> cnt(k, 0), nxt = cnt, sum = cnt;
        for (int a: nums) {
            fill(nxt.begin(), nxt.end(), 0);
            for (ll i = 0; i < k; i++) nxt[i * a % k] += cnt[i];
            nxt[a % k]++;
            swap(cnt, nxt);
            for (int i = 0; i < k; i++) sum[i] += cnt[i];
        }
        return sum;
    }
};