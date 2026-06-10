// Last updated: 6/10/2026, 7:12:39 PM
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0 ; i<n-2 ; i++) {
            // cout<<(nums[i] + nums[i+2])<<' '<<(nums[i+1] / 2)<<endl;
            if(2*(nums[i] + nums[i+2]) == nums[i+1]){
                ans++;
                // cout<<i<<endl;
            }
        }
        return ans;
    }
};