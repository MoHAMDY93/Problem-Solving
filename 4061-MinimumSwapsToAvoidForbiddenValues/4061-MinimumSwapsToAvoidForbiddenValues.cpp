// Last updated: 6/10/2026, 7:10:01 PM
class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int bad = 0 , n = nums.size() , maxi = 0;
        map<int , int> a , b , c;
        for(int i=0 ; i<n ; i++) {
            if(nums[i] == forbidden[i]) {
                bad++;
                c[nums[i]]++;
                maxi = max(maxi , c[nums[i]]);
            }
            a[nums[i]]++ , b[forbidden[i]]++;
        }
        for(auto p : a) {
            if(p.second > n - b[p.first]) return -1;
        }
        return max(maxi , (bad+1) / 2);
    }
};