// Last updated: 6/10/2026, 7:25:03 PM
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort (begin(nums) , end(nums));
        vector<pair<int , int>> a;
        int cnt = 0 , prev = nums[0];
        for (auto num : nums) {
            if (num == prev) cnt++;
            else {
                a.push_back({cnt , prev});
                prev = num , cnt = 1;
            }
        }
        a.push_back({cnt , prev});
        sort(rbegin(a) , rend(a));
        vector<int> res;
        for (int i=0 ; i<k ; i++) {
            res.push_back(a[i].second);
        }
        return res;        
    }
};