class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> l(26, -1), r(26, n), ord(26);
        iota(ord.begin(), ord.end(), 0);
        for (int i: ord) {
            for (int j = 0; j < n; j++) {
                if (s[j] == i + 'a') {
                    if (l[i] < 0) l[i] = j;
                    r[i] = j;
                }
            }
        }

        sort(ord.begin(), ord.end(), [&](int i, int j){ return l[i] < l[j]; });
        for (int i: ord) {
            if (l[i] < 0) continue;
            for (int j = l[i]; j <= r[i]; j++) {
                l[i] = min(l[i], l[s[j] - 'a']);
                r[i] = max(r[i], r[s[j] - 'a']);
            }
        }
        sort(ord.begin(), ord.end(), [&](int i, int j){ return r[i] < r[j]; });

        int mxr = -1;
        vector<string> ans;
        for (int i: ord) {
            if (mxr < l[i]) {
                mxr = r[i];
                ans.emplace_back(s.begin() + l[i], s.begin() + r[i] + 1);
            }
        }
        return ans;
    }
};