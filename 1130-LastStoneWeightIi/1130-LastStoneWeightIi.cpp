// Last updated: 6/10/2026, 7:22:25 PM
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        /*
            put + or - before any element, the total number of + and the total number of - whould be n / 2
            now the ans would be the min of | total - 2*subset_sum | over all possible subsets
        */
        int n = stones.size();
        int total = accumulate(stones.begin() , stones.end() , 0);
        vector<vector<int>> memo(n , vector<int>(total+1 , -1));
        function<int(int , int)> dp = [&](int i , int s) -> int {
            if (i == n) return abs(total - 2*s);
            auto& ret = memo[i][s];
            if (ret != -1) return ret;
            
            ret = dp(i + 1 , s);
            ret = min(ret , dp(i + 1 , s + stones[i]));
            
            return ret;
        };
        return dp(0 , 0);
    }
};