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
            auto [left_count , left_sum] = dfs(root->left);
            auto [right_count , right_sum] = dfs(root->right);
            int count = left_count + right_count + 1;
            int sum = left_sum + right_sum + root->val;
            // cout << root->val << ' ' << total.first << ' ' << total.second << '\n';
            ans += ((sum / count) == root->val);
            return {count , sum};
        };
        dfs(root);
        return ans;
    }
};