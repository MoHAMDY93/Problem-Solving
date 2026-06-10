// Last updated: 6/10/2026, 7:13:21 PM
class Solution {
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> sizes;

        // Returns {size, depth} and updates sizes if the subtree is perfect
        function<pair<int,int>(TreeNode*)> dfs = [&](TreeNode* node) -> pair<int,int> {
            if(!node) return {0, 0};
            
            auto [lsize, ldepth] = dfs(node->left);
            auto [rsize, rdepth] = dfs(node->right);
            
            int sz = 1 + lsize + rsize;
            int d = 1 + max(ldepth, rdepth);

            if(sz == (1 << d) - 1) sizes.push_back(sz); // perfect subtree
            return {sz, d};
        };

        dfs(root);

        if(sizes.size() < k) return -1;
        sort(sizes.rbegin(), sizes.rend());
        return sizes[k-1];
    }
};
