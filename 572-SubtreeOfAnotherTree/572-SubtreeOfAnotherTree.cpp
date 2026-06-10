// Last updated: 6/10/2026, 7:24:33 PM
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        function<bool(TreeNode* , TreeNode*)> check2 = [&](TreeNode* p , TreeNode* q) {
            if(p == nullptr && q == nullptr)
                return true;
            if(p == nullptr || q == nullptr)
                return false;
            if(p->val != q->val)
                return false;
            return check2(p->left, q->left) && check2(p->right, q->right);
        };
        function<bool(TreeNode*)> check = [&](TreeNode* curr) {
            if(curr == nullptr) return false;
            if(check2(curr , subRoot)) return true;
            return check(curr->left) || check(curr->right);
        };
        return check(root);
    }
};