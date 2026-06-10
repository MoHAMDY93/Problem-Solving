// Last updated: 6/10/2026, 7:13:04 PM
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1 , prev = 0 , ans = 0;
        for(int i=1 ; i<n ; i++) {
            if(nums[i] > nums[i-1]) cnt++;
            else {
                prev = cnt;
                cnt = 1;
            } 
            ans = max({ans , min(prev , cnt) , cnt / 2});
        }
        return ans;
    }   
};