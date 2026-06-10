// Last updated: 6/10/2026, 7:10:45 PM
class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = distance.size();
        vector<pair<int , int>> a;
        for (int i=0 ; i<n ; i++) 
            a.push_back({robots[i] , distance[i]});
        sort(a.begin() , a.end());
        sort(walls.begin() , walls.end());

        vector<vector<int>> memo(n , vector<int>(2 , -1));

        auto dp = [&](this auto&& dp , int i , int j) -> int {
            if (i < 0) 
                return 0;
            
            auto& ret = memo[i][j];
            
            if (ret != -1) 
                return ret;

            // first we will shot left
            {
                int left = a[i].first - a[i].second;
                if (i > 0)
                    left = max(left , a[i-1].first + 1);
                
                int l = lower_bound(walls.begin() , walls.end() , left) - walls.begin();
                int r = upper_bound(walls.begin() , walls.end() , a[i].first) - walls.begin();

                ret = dp(i-1 , 0) + (r - l);
            }
            // then we will shot right, make sure u donn double count the overlapping
            {
                int right = a[i].first + a[i].second;
                if (i+1 < n) {
                    // if the i+1_robot shot right then the only obstacle will be the right robot itself,
                    // but if the robot shot left, so we gonna stop at the end of its range so we donn double count 
                    if (j == 1)
                       right = min(right , a[i+1].first - 1);
                    else
                        right = min(right , a[i+1].first - a[i+1].second - 1);
                }
                int l = lower_bound(walls.begin() , walls.end() , a[i].first) - walls.begin();
                int r = upper_bound(walls.begin() , walls.end() , right) - walls.begin();

                ret = max(ret , dp(i-1 , 1) + (r - l));
            } 

            return ret;
        };

        return dp(n-1 , 1);
    }
};