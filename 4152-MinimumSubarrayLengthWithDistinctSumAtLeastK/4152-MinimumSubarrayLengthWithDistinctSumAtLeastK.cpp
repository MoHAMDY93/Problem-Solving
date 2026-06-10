// Last updated: 6/10/2026, 7:08:54 PM
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        long long l=0 , ans = INT_MAX , sum = 0;
        unordered_map<int , int> st;
        // set<int> st;
        for(int r=0 ; r<nums.size() ; r++) {
            if(st[nums[r]] == 0) sum += nums[r];
            st[nums[r]]++;
            while(sum >= k) {
                ans = min(ans , r - l + 1);
                // auto itr = st.find(nums[l]);
                // st.erase(itr);
                // itr = st.find(nums[l]);
                
                if(st[nums[l]] == 1) sum -= nums[l];
                st[nums[l]]--;
                l++;
                // ans = min(ans , r - l + 1) , sum -= nums[l++];
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};