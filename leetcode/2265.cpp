struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int averageOfSubtree(TreeNode *root) {
        int ans = 0;
        function<pair<int, int>(TreeNode*)> dfs = [&](TreeNode *cur) {
            int sum = cur->val, cnt = 1;
            if (cur->left) {
                auto [lsum, lcnt] = dfs(cur->left);
                sum += lsum, cnt += lcnt;
            }
            if (cur->right) {
                auto [rsum, rcnt] = dfs(cur->right);
                sum += rsum, cnt += rcnt;
            }
            if (sum / cnt == cur->val) ans++;
            return make_pair(sum, cnt);
        };
        dfs(root);
        return ans;
    }
};