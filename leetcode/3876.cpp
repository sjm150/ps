class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int o = count_if(nums1.begin(), nums1.end(), [](int a){ return a % 2; });
        return o == 0 || o == nums1.size() || *min_element(nums1.begin(), nums1.end()) % 2;
    }
};