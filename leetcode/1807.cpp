class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> m;
        for (auto &k: knowledge) m[k[0]] = k[1];

        int n = s.size(), lst = -1;
        string res;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                lst = i;
            } else if (s[i] == ')') {
                auto it = m.find(s.substr(lst + 1, i - lst - 1));
                res += it != m.end() ? it->second : "?";
                lst = -1;
            } else {
                if (lst < 0) res.push_back(s[i]);
            }
        }

        return res;
    }
};