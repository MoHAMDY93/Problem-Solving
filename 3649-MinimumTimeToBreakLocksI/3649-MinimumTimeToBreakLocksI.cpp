// Last updated: 6/10/2026, 7:12:51 PM
class Solution {
public:
    int findMinimumTime(vector<int>& strength, int k) {
        sort(strength.begin() , strength.end());
        int ans = INT_MAX;
        do {    
            int curr = 1 , sum = 0;
            for(auto i : strength) {
                sum += ceil(1.0 * i / curr);
                curr += k;
            }
            ans = min(ans , sum);
        } while(next_permutation(strength.begin() , strength.end()));
        return ans;
    }
};