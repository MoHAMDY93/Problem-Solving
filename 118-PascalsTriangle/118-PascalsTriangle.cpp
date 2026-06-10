// Last updated: 6/10/2026, 7:26:43 PM
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int row=1 ; row<=numRows ; row++) {
            if(row == 1)
                ans.push_back({1});
            else if(row == 2)
                ans.push_back({1 , 1});
            else {
                vector<int> temp = {1};
                for(int j=1 ; j<row-1 ; j++) {
                    temp.push_back(ans[row-2][j] + ans[row-2][j-1]);
                }
                temp.push_back(1);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};