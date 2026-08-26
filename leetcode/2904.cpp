class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        for (int len = k; len <= n; len++) {
            bool fnd = false;
            string ans;

            int cnt = count(s.begin(), s.begin() + len, '1');
            if (cnt >= k) {
                if (!fnd) {
                    ans = s.substr(0, len);
                    fnd = true;
                }
            }
            for (int i = len; i < n; i++) {
                cnt += s[i] - s[i - len];
                if (cnt >= k) {
                    string ss = s.substr(i - len + 1, len);
                    if (!fnd) {
                        ans = ss;
                        fnd = true;
                    } else if (ans > ss) {
                        ans = ss;
                    }
                }
            }

            if (fnd) return ans;
        }
        return "";
    }
};