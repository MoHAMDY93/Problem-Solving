// Last updated: 6/10/2026, 7:13:07 PM
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0 ; i<n ; i++) {
            bool ok1 = false , ok2 = false;
            if(i+k-1 < n) {
                int j = i+1;
                while(j < i+k && nums[j] > nums[j-1]) j++;
                ok1 = (j == i+k);
            } 
            if(i+2*k-1 < n) {
                int j = i+k+1;
                while(j < i+2*k && nums[j] > nums[j-1]) j++;
                ok2 = (j == i+2*k);
            }
            if(ok1 && ok2) return true;
        }
        return false;
    }
};