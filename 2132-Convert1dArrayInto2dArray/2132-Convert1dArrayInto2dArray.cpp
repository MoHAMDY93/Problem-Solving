// Last updated: 6/10/2026, 7:18:43 PM
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        vector<vector<int>>ans;
        if(m * n != size) 
            return ans;
        vector<int>temp;
        for(int i=0 ; i<size ; i++) {
            temp.push_back(original[i]);
            if((i+1) % n == 0) {
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};