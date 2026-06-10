// Last updated: 6/10/2026, 7:09:45 PM
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long ans = 0;
        long long mx1 = INT_MIN , mx2 = INT_MIN;
        for(auto i : nums) {
            if(abs(i) > mx1) mx2 = mx1 , mx1 = abs(i);
            else if(abs(i) > mx2) mx2 = abs(i);
        }
        cout << mx1 << ' ' << mx2 << '\n';
        return (long long)1e5 * mx1 * mx2;
    }   
};