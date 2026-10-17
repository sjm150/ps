class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> sa(n);
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = nums[i]; j; j /= 10) sum += j % 10;
            sa[i] = make_pair(sum, nums[i]);
        }

        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j){ return sa[i] < sa[j]; });

        vector<bool> vst(n, false);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vst[i]) {
                for (int j = i; !vst[j]; j = ord[j]) vst[j] = true;
                cnt++;
            }
        }
        return n - cnt;
    }
};