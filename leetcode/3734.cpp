class Solution {
    string reverse_of(const string &s) {
        auto r = s;
        reverse(r.begin(), r.end());
        return r;
    }

    string build_pal(const string &half, const string &mid) {
        return half + mid + reverse_of(half);
    }

    pair<bool, string> make_same(vector<int> &cnt, const string &target) {
        int n = target.size();
        for (int i = 0; i < n; i++) {
            if (cnt[target[i] - 'a']) {
                cnt[target[i] - 'a']--;
            } else {
                return make_pair(false, "");
            }
        }
        return make_pair(true, target);
    }

    pair<bool, string> make_greater(const vector<int> &cnt, const string &target) {
        int n = target.size();
        for (int i = n - 1; i >= 0; i--) {
            auto cur = cnt;
            auto [ok, result] = make_same(cur, target.substr(0, i));
            if (!ok) continue;

            ok = false;
            for (int j = target[i] - 'a' + 1; j < 26; j++) {
                if (cur[j]) {
                    result += j + 'a';
                    cur[j]--;
                    ok = true;
                    break;
                }
            }
            if (!ok) continue;

            for (int j = i + 1; j < n; j++) {
                for (int k = 0; k < 26; k++) {
                    if (cur[k]) {
                        result += k + 'a';
                        cur[k]--;
                        break;
                    }
                }
            }

            return make_pair(true, result);
        }

        return make_pair(false, "");
    }

public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size(), m = n / 2;;
        string ht = target.substr(0, m);
        vector<int> cnt(26, 0);
        for (char c: s) cnt[c - 'a']++;

        string mid = "";
        int oc = accumulate(cnt.begin(), cnt.end(), 0, [](int t, int c){ return t + c % 2; });
        if (n % 2) {
            if (oc != 1) return "";
            auto it = find_if(cnt.begin(), cnt.end(), [](int c){ return c % 2 == 1; });
            mid += it - cnt.begin() + 'a';
            *it--;
        } else if (oc) {
            return "";
        }
        for (int &c: cnt) c /= 2;

        {
            auto cur = cnt;
            auto [ok, result] = make_same(cur, ht);
            if (ok) {
                string pal = build_pal(result, mid);
                if (pal > target) return pal;
            }
        }

        auto [ok, result] = make_greater(cnt, ht);
        return ok ? build_pal(result, mid) : "";
    }
};