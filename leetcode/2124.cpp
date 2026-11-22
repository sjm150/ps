class Solution {
public:
    bool checkString(string s) {
        auto it = find(s.begin(), s.end(), 'b');
        return find(it, s.end(), 'a') == s.end();
    }
};