// Last updated: 6/10/2026, 7:24:17 PM
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> ans;
        int n = nums.size();
        for(auto i : nums) {
            if(!st.insert(i).second) ans.push_back(i);
        }
        for(int i=1 ; i<=n ; i++) if(!st.count(i)) ans.push_back(i);
        return ans;
    }
};