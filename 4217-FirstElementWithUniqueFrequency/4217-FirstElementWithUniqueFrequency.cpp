// Last updated: 6/10/2026, 7:08:20 PM
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int , int> freq , cnt;
        for(auto i : nums)
            freq[i]++;
        for(auto [_ , c] : freq)
            cnt[c]++;
        for(auto i : nums)
            if(cnt[freq[i]] == 1)
                return i;
        return -1;
    }
};