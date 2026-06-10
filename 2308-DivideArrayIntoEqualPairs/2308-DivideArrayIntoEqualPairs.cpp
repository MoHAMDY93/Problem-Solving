// Last updated: 6/10/2026, 7:17:34 PM
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int>a(501 , 0);
        for(int num : nums){
            a[num]++;
        }
        for(int i : a){
            if(i % 2 != 0)
                return false;
        }
        return true;
    }
};