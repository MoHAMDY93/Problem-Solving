// Last updated: 6/10/2026, 7:08:26 PM
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> f1, f2, total;

        for(int x : nums1) f1[x]++, total[x]++;
        for(int x : nums2) f2[x]++, total[x]++;

        for(auto &[v,c] : total){
            if(c % 2) return -1;
        }

        int cost = 0;

        for(auto &[v,c] : total){
            int target = c / 2;
            if(f1[v] > target)
                cost += f1[v] - target;
        }

        return cost;
    }
};