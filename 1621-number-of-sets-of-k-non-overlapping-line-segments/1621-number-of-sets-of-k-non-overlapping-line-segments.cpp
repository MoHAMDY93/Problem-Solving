class Solution {
public:
    int numberOfSets(int n, int k) {
        vector<vector<vector<int>>> memo(n , vector<vector<int>> (k+1 , vector<int>(2 , -1)));
        /*
            at any point i can :
            if ok is false -> means i donn have a valid segment yet
            {
                so i can skip the current point
                or 
                add it and ok become true
            }
            else -> i already have a vlid segment
            {
                i can add this point to me and keep cnt as it is
                or 
                separate the curr segment and incerement cnt
            }
        */
        int mod = 1e9 + 7;
        auto dp = [&](this auto&& dp , int i , int cnt , int ok) -> int {
            if (cnt > k) return 0;
            if (i == n) return (cnt == k && !ok);
            auto& ret = memo[i][cnt][ok];
            if (~ret) return ret;
            ret = 0;
            if (!ok) {
                ret = dp(i+1 , cnt , 0) % mod;
                ret = (ret + dp(i+1 , cnt , 1) % mod) % mod;
            } else {
                ret = dp(i+1 , cnt , 1) % mod;
                ret = (ret + dp(i , cnt+1 , 0) % mod) % mod;
            }

            return ret;
        };
        return dp(0 , 0 , 0);
    }
};