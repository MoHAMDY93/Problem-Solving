// Last updated: 6/10/2026, 7:24:38 PM
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
    int diameterOfBinaryTree(TreeNode* root) {
        TreeNode* curr = root;
        int diameter = 0;
        function<int(TreeNode*)> get = [&](TreeNode* curr) {
            if(curr == nullptr) return 0;
            int left = get(curr->left);
            int right = get(curr->right);
            diameter = max(diameter , left + right);
            return 1 + max(left , right);
        };
        get(root);
        return diameter; 
    }
};