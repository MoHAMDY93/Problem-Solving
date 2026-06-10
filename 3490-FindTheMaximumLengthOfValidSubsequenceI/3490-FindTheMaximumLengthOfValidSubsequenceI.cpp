// Last updated: 6/10/2026, 7:13:30 PM
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int parity = (nums[0] & 1);
        int mx1 = 1 , mx2 = 1 , mx3 = 0;
        for (int i = 1 ; i < n ; i++) {
            int curr = (nums[i] & 1);
            if(curr != parity) {
                mx1 ++;
                parity = curr;
            }
        }
        parity = (nums[0] & 1);
        for (int i = 1 ; i < n ; i++) {
            int curr = (nums[i] & 1);
            if(curr == parity) {
                mx2 ++;
            }
        }
        parity = !(nums[0] & 1);
        for (int i = 1 ; i < n ; i++) {
            int curr = (nums[i] & 1);
            if(curr == parity) {
                mx3 ++;
            }
        }
        
        return max({mx1 , mx2 , mx3});
    }
};