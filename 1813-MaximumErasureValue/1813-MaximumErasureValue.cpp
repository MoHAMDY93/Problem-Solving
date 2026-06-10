// Last updated: 6/10/2026, 7:19:53 PM
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int mx = 0 , curr = 0 , l=0 , r = 0 , n = nums.size();
        set<int> st;
        while(r < n) {
            if(!st.count(nums[r])) {
                // cout << nums[r] << "\n";
                curr += nums[r] , st.insert(nums[r]) , r++;
                mx = max(curr , mx);
            } else {
                while(st.count(nums[r])) {
                    curr -= nums[l];
                    st.erase(nums[l]);
                    l++;
                }
                curr += nums[r] ,st.insert(nums[r]) , r++;
            }
            // cout << curr << "\n"; 
        }
        return mx;
    }
};