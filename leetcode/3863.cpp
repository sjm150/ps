class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] > s[i + 1]) {
                ok = false;
                break;
            }
        }
        if (ok) return 0;
        if (n == 2) return -1;
        int mn = *min_element(s.begin(), s.end()), mx = *max_element(s.begin(), s.end());
        if (s[0] == mn || s[n - 1] == mx) return 1;
        else if (mn == *min_element(s.begin() + 1, s.end() - 1) || mx == *max_element(s.begin() + 1, s.end() - 1)) return 2;
        else return 3;
    }
};