// Last updated: 6/10/2026, 7:23:18 PM
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return nullptr;
        unordered_map<TreeNode* , TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;
        vector<TreeNode*> last;

        while(!q.empty()) {
            int size = q.size();
            last.clear();
            for(int i=0 ; i<size; i++) {
                TreeNode* node = q.front(); q.pop();
                last.push_back(node);
                if(node->left) {
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if(node->right) {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        unordered_set<TreeNode*> deep(last.begin() , last.end());
        while(deep.size() > 1) {
            unordered_set<TreeNode*> next;
            for(auto node : deep) next.insert(parent[node]);
            deep = next;
        }
        return *deep.begin();
    }
};