// Last updated: 6/10/2026, 7:26:44 PM
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
    bool isBalanced(TreeNode* root) {
        function<int(TreeNode*)> check = [&](TreeNode* curr) {
            if(curr == nullptr) return 0;
            int left = check(curr->left);
            int right = check(curr->right);
            if(left == -1 || right == -1 || abs(left - right) > 1) return -1;
            return 1 + max(left , right);
        };
        return check(root) != -1;
    }
};