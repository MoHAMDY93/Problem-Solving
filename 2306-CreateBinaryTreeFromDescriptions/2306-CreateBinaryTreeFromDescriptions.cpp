// Last updated: 6/10/2026, 7:17:37 PM
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> isChild;
        for (const auto& desc : descriptions) {
            int par = desc[0] , child = desc[1];
            bool isLeft = desc[2];
            if (!nodeMap.count(par)) {
                nodeMap[par] = new TreeNode(par);
            }
            if (!nodeMap.count(child)) {
                nodeMap[child] = new TreeNode(child);
            }
            if (isLeft) {
                nodeMap[par]->left = nodeMap[child];
            } else {
                nodeMap[par]->right = nodeMap[child];
            }
            isChild.insert(child);
        }
        for (const auto& desc : descriptions) {
            if (!isChild.count(desc[0])) return nodeMap[desc[0]];
        }
        return nullptr;
    }
};