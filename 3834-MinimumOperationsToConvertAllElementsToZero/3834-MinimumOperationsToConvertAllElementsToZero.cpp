// Last updated: 6/10/2026, 7:11:49 PM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> st;
        int i = 0;
        while(i < n) {
            if(nums[i] == 0) { i++; continue; }
            st.clear();
            while(i < n && nums[i] != 0) {
                int x = nums[i];
                while(!st.empty() && st.back() > x) st.pop_back();
                if(st.empty() || st.back() < x) st.push_back(x) , ans++;
                i++;
            }
            // for(auto i : st) cout << i << ' ';
            // cout << '\n'; 
        }
        return ans;
    }
};