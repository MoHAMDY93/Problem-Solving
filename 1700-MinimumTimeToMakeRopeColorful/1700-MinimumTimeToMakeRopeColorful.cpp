// Last updated: 6/10/2026, 7:20:23 PM
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        colors.push_back('*');
        neededTime.push_back(0);
        int n = colors.size();
        char prev = colors[0];
        int mx = neededTime[0] , others = neededTime[0] , ans = 0;
        for(int i=1 ; i<n ; i++) {
            if(colors[i] == prev) mx = max(mx , neededTime[i]) , others += neededTime[i];
            else {
                ans += others - mx;
                mx = others = neededTime[i];
                prev = colors[i]; 
            }
        }
        return ans;
    }   
};