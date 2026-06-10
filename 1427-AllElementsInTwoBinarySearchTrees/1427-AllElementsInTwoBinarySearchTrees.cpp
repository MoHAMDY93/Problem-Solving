// Last updated: 6/10/2026, 7:21:32 PM
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        function<void(TreeNode*)> get = [&](TreeNode* node) {
            if (node == nullptr) return;
            ans.push_back(node->val);
            get(node->left);
            get(node->right);
        };
        get(root1);
        get(root2);
        sort(begin(ans) , end(ans));
        return ans;
    }
};