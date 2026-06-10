// Last updated: 6/10/2026, 7:26:46 PM
class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        for(int i=1 ; i<a.size() ; i++) {
            for(int j=0 ; j<a[i].size() ; j++){ 
                if(j+1 == a[i].size())
                    a[i][j] += a[i-1][j-1];
                else if(j == 0)
                    a[i][j] += a[i-1][j];
                else
                    a[i][j] += min(a[i-1][j-1] , a[i-1][j]);
            }
        }
        return (int)(*min_element(a.back().begin() , a.back().end()));
    }
};