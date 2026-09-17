const int mx = 1e6;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size(), l = 0, sum = 0, ans = mx;
        vector<int> mn(n, mx);
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            while (target < sum) sum -= arr[l++];
            if (target == sum) {
                mn[i] = i - l + 1;
                if (l) ans = min(ans, mn[l - 1] + i - l + 1);
            }
            if (i) mn[i] = min(mn[i], mn[i - 1]);
        }
        return ans < mx ? ans : -1;
    }
};