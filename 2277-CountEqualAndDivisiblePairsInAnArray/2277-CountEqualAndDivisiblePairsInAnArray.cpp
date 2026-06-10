// Last updated: 6/10/2026, 7:17:43 PM
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int cnt = 0 , n = nums.size();
        for(int i=0 ; i<n ; i++) {
            for(int j = i+1 ; j<n ; j++) {
                if(nums[i] == nums[j] && ((i*j) % k == 0))
                    cnt++;
            }
        }
        return cnt;   
    }
};