// Last updated: 6/10/2026, 7:13:01 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        if(nums[0] < k) return -1;
        set<int> st;
        for(int i : nums) {
            if(i > k) st.insert(i);
        } 
        return st.size();
    }
};