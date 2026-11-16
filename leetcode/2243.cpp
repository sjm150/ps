class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            int n = s.size();
            string t;
            for (int i = 0; i < n; i += k) {
                int sum = 0;
                for (int j = i; j < min(i + k, n); j++) sum += s[j] - '0';
                t += to_string(sum);
            }
            swap(s, t);
        }
        return s;
    }
};