// Last updated: 6/10/2026, 7:14:08 PM
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>a , b;
        a.push_back(nums[0]);
        b.push_back(nums[1]);

        for(int i = 2 ; i < n ; i++) {
            if(a.back() > b.back())
                a.push_back(nums[i]);
            else 
                b.push_back(nums[i]);
        }
        vector<int>res;
        for(int i : a)
            res.push_back(i);
        for(int i : b)
            res.push_back(i);
        return res;            
    }
};