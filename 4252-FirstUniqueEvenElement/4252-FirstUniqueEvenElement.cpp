// Last updated: 6/10/2026, 7:08:31 PM
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n = nums.size();
        map<int , int> mp;
        for (int i =0 ; i<n ; i++) {
            mp[nums[i]]++; 
        }
        for (int i=0 ; i<n ; i++) {
            if (!(nums[i] & 1) && mp[nums[i]] == 1) return nums[i];
        }
        return -1;
    }
};