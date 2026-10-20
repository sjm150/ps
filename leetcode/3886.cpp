class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> dec;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) dec.push_back(i);
        }
        dec.push_back(n + 1);
        dec.push_back(n + 1);

        auto chk = [&](int k) {
            vector<int> s;
            int idx = 0;
            for (int l = 0; l < n; l += k) {
                int r = l + k - 1;
                while (dec[idx] < l) idx++;
                if (dec[idx] < r) {
                    if (dec[idx + 1] < r) {
                        return false;
                    } else {
                        if (nums[l] < nums[r]) return false;
                        else s.push_back(nums[dec[idx] + 1]), s.push_back(nums[dec[idx]]);
                    }
                } else {
                    s.push_back(nums[l]);
                    s.push_back(nums[r]);
                }
            }

            int sz = s.size();
            for (int i = 0; i < sz - 1; i++) {
                if (s[i] > s[i + 1]) return false;
            }

            return true;
        };

        int sum = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i) continue;
            if (chk(i)) sum += i;
            if (i != n / i && chk(n / i)) sum += n / i;
        }
        return sum;
    }
};