// Last updated: 6/10/2026, 7:14:35 PM
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>freq(n * n + 1 , 0) , ans;
        for(auto i : grid) {
            for(auto j : i){
                if(freq[j] == 0)
                    freq[j] = 1;
                else 
                    ans.push_back(j);
                
            }
        }
        for(int i = 1 ; i<= n*n ; i++)
            if(!freq[i])
                ans.push_back(i);

        return ans;
    }
};