/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        // retunr the count of the nodes in the subtree and sum of theor values
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> pair<int , int> {
            if (!root) return {0 , 0};
            if (!root->left && !root->right) {
                ans++;
                return {1 , root->val};
            }
            auto left_contr = dfs(root->left);
            auto right_contr = dfs(root->right);
            auto total = make_pair(left_contr.first + right_contr.first + 1 , left_contr.second + right_contr.second + root->val);
            // cout << root->val << ' ' << total.first << ' ' << total.second << '\n';
            ans += ((total.second / total.first) == root->val);
            return total;
        };
        dfs(root);
        return ans;
    }
};