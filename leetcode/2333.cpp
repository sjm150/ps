typedef long long ll;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        for (int i = 0; i < n; i++) nums1[i] = abs(nums1[i] - nums2[i]);

        int l = 0, r = *max_element(nums1.begin(), nums1.end());
        while (l < r) {
            int m = (l + r) / 2;
            ll cnt = 0;
            for (int a: nums1) {
                if (a > m) cnt += a - m;
            }
            if (cnt > k1 + k2) l = m + 1;
            else r = m;
        }

        int rem = k1 + k2;
        for (int &a: nums1) {
            if (a > r) {
                rem -= a - r;
                a = r;
            }
        }
        for (int &a: nums1) {
            if (!rem) break;
            if (a && a == r) {
                a--;
                rem--;
            }
        }

        return accumulate(nums1.begin(), nums1.end(), 0ll, [](ll acc, int a){ return acc + ll(a) * a; });
    }
};