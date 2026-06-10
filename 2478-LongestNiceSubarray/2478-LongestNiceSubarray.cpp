// Last updated: 6/10/2026, 7:16:54 PM
class Solution {
public:
    bool check(int length, vector<int>& nums){
        if(length <= 1) return true;
        for(int i=0 ; i <= nums.size()-length ; i++) {
            int bits = 0;
            bool nice = true;
            for(int j = i ; j < i + length ; j++) {
                if((bits & nums[j]) != 0){
                    nice = false;
                    break;
                }
                bits |= nums[j];
            }
            if(nice)
                return true;
        }
        return false;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0, r = nums.size(), ans = 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(check(mid , nums)) {
                ans = mid;
                l = mid + 1;
            } else 
                r = mid - 1;
        }
        return ans;
    }   
};