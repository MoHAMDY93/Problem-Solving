// Last updated: 6/10/2026, 7:21:25 PM
class Solution {
public:
    int minimumDistance(string word) {
        vector<pair<int , int>> v(26);
        for (int i=0 ; i<26 ; i++) {
            v[i] = {i / 6 , i % 6};
        }
        auto dist = [&](char a, char b) {
            int ai = a - 'A', bi = b - 'A';
            return abs(v[ai].first - v[bi].first) + abs(v[ai].second - v[bi].second);
        };
        int n = word.size();
        vector<vector<int>> memo(n+1 , vector<int>(n+1 , -1));
        auto dp = [&](this auto&& dp , int k , int i) -> int {
            if (k == n) return 0;
            
            auto& ret = memo[k][i];
            if (~ret) return ret;
            
            // use first finger
            int first = dp(k+1 , i) + (k == 0 ? 0 : dist(word[k] , word[k-1]));

            // use second finger
            int second = dp(k+1 , k) + (i == 0 ? 0 : dist(word[i-1] , word[k])); 
            
            return ret = min(first , second);
        };      
        // return 0;
        return dp(0 , 0);
    }
};