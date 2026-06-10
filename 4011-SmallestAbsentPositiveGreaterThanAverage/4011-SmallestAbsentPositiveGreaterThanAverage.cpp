// Last updated: 6/10/2026, 7:10:32 PM
class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        set<int> st(begin(nums) , end(nums));
        double avg = ((1.0 * accumulate(begin(nums) , end(nums) , 0)) / nums.size());
        int ans = max((int)floor(avg)+1 , 1);
        while(st.count(ans)) ans++;
        return ans;
    }
};