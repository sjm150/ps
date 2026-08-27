class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c: s) cnt[c - 'a']++;

        for (int i = n - 1; i >= 0; i--) {
            auto cur = cnt;
            string ans = "";

            bool poss = true;
            for (int j = 0; j < i; j++) {
                if (cur[target[j] - 'a']) {
                    ans += target[j];
                    cur[target[j] - 'a']--;
                } else {
                    poss = false;
                    break;
                }
            }
            if (!poss) continue;

            bool ok = false;
            for (int j = target[i] - 'a' + 1; j < 26; j++) {
                if (cur[j]) {
                    ans += j + 'a';
                    cur[j]--;
                    ok = true;
                    break;
                }
            }
            if (!ok) continue;

            for (int j = i + 1; j < n; j++) {
                for (int k = 0; k < 26; k++) {
                    if (cur[k]) {
                        ans += k + 'a';
                        cur[k]--;
                        break;
                    }
                }
            }

            return ans;
        }

        return "";
    }
};