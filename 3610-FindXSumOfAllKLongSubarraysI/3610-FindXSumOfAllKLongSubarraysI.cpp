// Last updated: 6/10/2026, 7:13:11 PM
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        map<int , int> mp;
        vector<int> ans;
        int l = 0;
        for(int r=0 ; r<n ; r++) {
            mp[nums[r]]++;
            if(r+1 >= k) {
                vector<pair<int , int>> v;
                for(auto [val , cnt] : mp) v.push_back({cnt , val});
                sort(rbegin(v) , rend(v)); 
                int sum = 0;
                for(int i=0 ; i < v.size() && i<x ; i++) {
                    sum += v[i].first * v[i].second;
                }
                ans.push_back(sum);
                mp[nums[l++]]--;
            }
        }
        return ans;
    }
};