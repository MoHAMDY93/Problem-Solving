// Last updated: 6/10/2026, 7:14:46 PM
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zs_1 = 0 , zs_2 = 0;
        long long sum_1 = 0 , sum_2 = 0;
        for(int num : nums1) {
            zs_1 += (num == 0);
            sum_1 += num;
        } 
        for(int num : nums2) {
            zs_2 += (num == 0);
            sum_2 += num;
        }
        if(zs_1 && zs_2) {
            return max(sum_1 + zs_1 , sum_2 + zs_2);
        } else if(zs_1 == 0 && zs_2 == 0) {
            if(sum_1 != sum_2)
                return -1;
            else 
                return sum_1;
        } else if(zs_1 == 0) {
            if(sum_2 + zs_2 > sum_1)
                return -1;
            else 
                return sum_1;
        } else {
            if(sum_1 + zs_1 > sum_2)
                return -1;
            else 
                return sum_2;
        }
    }
};