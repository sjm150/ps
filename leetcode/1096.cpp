class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        vector<char> op;
        vector<vector<string>> s;

        auto mult = [&]() {
            if (op.empty() || op.back() != '*') return;
            int sz = s.size();
            assert(sz > 1);

            vector<string> p;
            for (auto &h: s[sz - 2]) {
                for (auto &t: s[sz - 1]) p.push_back(h + t);
            }
            s.pop_back();
            s.pop_back();
            s.push_back(p);
            op.pop_back();
        };
        auto add_all = [&]() {
            while (op.back() != '{') {
                if (op.back() == '*') {
                    op.pop_back();
                    continue;
                }
                assert(op.back() == '+');
                int sz = s.size();
                assert(sz > 1);
                s[sz - 2].insert(s[sz - 2].end(), s[sz - 1].begin(), s[sz - 1].end());
                s.pop_back();
                op.pop_back();
            }
            op.pop_back();
        };

        for (char c: expression) {
            if (c == '{') {
                op.push_back('{');
            } else if (c == '}') {
                add_all();
                mult();
                op.push_back('*');
            } else if (c == ',') {
                op.push_back('+');
            } else {
                s.push_back({{c}});
                mult();
                op.push_back('*');
            }
        }

        sort(s[0].begin(), s[0].end());
        s[0].erase(unique(s[0].begin(), s[0].end()), s[0].end());
        return s[0];
    }
};