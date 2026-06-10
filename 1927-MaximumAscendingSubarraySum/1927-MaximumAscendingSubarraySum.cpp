// Last updated: 6/10/2026, 7:19:25 PM
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0] , ans=0;
        for(int i=1 ; i<n ; i++){
            if(nums[i]<=nums[i-1]){
                ans = max(ans , sum);
                sum=nums[i];
            }
            else
                sum+=nums[i];
        }
        return max(sum, ans);
    }
};