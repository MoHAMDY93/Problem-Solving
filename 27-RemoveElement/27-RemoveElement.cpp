// Last updated: 6/10/2026, 7:27:52 PM
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt=0;
        for(int i : nums){
            if(i != val)
                nums[cnt++] = i;
        }
        return cnt; 
    }
};