// Last updated: 6/10/2026, 7:15:33 PM
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> color(n , 0);
        vector<int> ans;
        int count = 0;
        for (auto q : queries) {
            int idx = q[0] , c = q[1];
            // remove the olde one
            if (color[idx] != 0) {
                if (idx - 1 >= 0 && color[idx] == color[idx - 1]) count--;
                if (idx + 1 <  n && color[idx] == color[idx + 1]) count--;
            }
            
            color[idx] = c;
            if (idx - 1 >= 0 && color[idx] == color[idx - 1]) count++;
            if (idx + 1 <  n && color[idx] == color[idx + 1]) count++;

            ans.push_back(count);
        }
        return ans;
    }
};