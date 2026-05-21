class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string , int> mp;
        for (auto x : arr1) {
            string s = to_string(x);
            string curr = "";
            for (auto c : s) curr.push_back(c) , mp[curr]++;
        }
        int ans = 0;
        for (auto x : arr2) {
            string s = to_string(x);
            string curr = "";
            for (auto c : s) {
                curr.push_back(c);
                if (mp.count(curr)) ans = max(ans , (int)curr.size());
            }
        }
        return ans;
    }
};