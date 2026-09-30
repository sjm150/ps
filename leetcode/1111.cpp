class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size(), dep = 0;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                dep++;
                res[i] = dep % 2;
            } else {
                res[i] = dep % 2;
                dep--;
            }
        }
        return res;
    }
};