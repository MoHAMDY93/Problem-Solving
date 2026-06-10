// Last updated: 6/10/2026, 7:15:56 PM
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int , int> mp;
        for(auto &i : nums) {
            i = ((i % value) + value) % value;
            // while(mp.count(i)) i+=value;
            mp[i]++;
        }
        int MEX = 0;
        while(true) {
            int r = MEX % value;
            if(mp[r] == 0) break;
            mp[r]--;
            MEX++;
        }
        return MEX;
    }
};