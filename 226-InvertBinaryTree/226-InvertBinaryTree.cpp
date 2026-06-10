// Last updated: 6/10/2026, 7:25:36 PM
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
    TreeNode* invertTree(TreeNode* root) {
        function<void(TreeNode*)> rev = [&](TreeNode* curr) {
            if(curr == nullptr) return;
            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;
            rev(curr->left);
            rev(curr->right);
        };
        rev(root);
        return root;
    }
};