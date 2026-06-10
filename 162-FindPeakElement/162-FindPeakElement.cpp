// Last updated: 6/10/2026, 7:26:15 PM
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /*
            can be solved with o(n) byt chcekking all the elements unitl we meet some peak element
            but we have to think about o(log(n)) solution, 
            this can be done by binary search or two pointers
        */
        int l = 0 , r = nums.size() - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] < nums[mid+1])
                l = mid+1;
            else 
                r = mid;
        }
        return l;
    }
};