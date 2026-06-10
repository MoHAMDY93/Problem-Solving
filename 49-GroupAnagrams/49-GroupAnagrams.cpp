// Last updated: 6/10/2026, 7:27:27 PM
class Solution {
public:
    long long compute_hash(string const& s) {
        const int p = 31;
        const int m = 1e9 + 9;
        long long hash_value = 0;
        long long p_pow = 1;
        for (char c : s) {
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return hash_value;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<long long , vector<string>> mp;
        for(auto str : strs) {
            string temp = str;
            sort(begin(temp) , end(temp));
            long long curr = compute_hash(temp);
            mp[curr].push_back(str);
        }
        vector<vector<string>> res;
        for(auto [k , v] : mp) {
            res.push_back(v); 
        }
        return res;     
    }
};