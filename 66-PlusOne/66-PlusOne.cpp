// Last updated: 6/10/2026, 7:27:19 PM
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n = digits.size();
        int rem = 1;
        for(int i=n-1 ; i>=0 ; i--) {
            ans.push_back((rem + digits[i]) % 10);
            rem = (rem + digits[i]) / 10;
        }
        if(rem) ans.push_back(rem);
        reverse(ans.begin() , ans.end());
        return ans;
    }
};