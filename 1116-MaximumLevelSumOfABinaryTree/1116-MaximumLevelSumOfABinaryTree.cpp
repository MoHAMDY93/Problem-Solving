// Last updated: 6/10/2026, 7:22:29 PM
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
    int maxLevelSum(TreeNode* root) {
        map<int , int> levSum;
        // int ans = INT_MAX , mx = INT_MIN;
        function<void(TreeNode* , int)> exp = [&](TreeNode* node , int lev) {
            if(node == nullptr) return;
            levSum[lev] += node->val;
            // cout << levSum[lev] << ' ' << lev << '\n';
            // if(levSum[lev] > mx) mx = levSum[lev] , ans = lev;
            // if(levSum[lev] == mx) ans = min(lev , ans);
            exp(node->right , lev+1);
            exp(node->left , lev+1);
        };
        exp(root , 1);
        auto it = max_element(levSum.begin() , levSum.end() , [](auto a , auto b) {
            if(a.second != b.second) return a.second < b.second;
            return a.first > b.first; 
        });
        return it->first;
    }
};