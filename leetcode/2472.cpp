class Solution {
public:
    int maxPalindromes(string s, int k) {
        auto pal = [&](int l, int r) {
            for (int i = 0; l + i < r - i; i++) {
                if (s[l + i] != s[r - i]) return false;
            }
            return true;
        };
        int n = s.size(), cnt = 0;
        for (int i = 0; i + k - 1 < n; i++) {
            if (pal(i, i + k - 1)) {
                cnt++;
                i = i + k - 1;
            } else if (i + k < n && pal(i, i + k)) {
                cnt++;
                i = i + k;
            }
        }
        return cnt;
    }
};