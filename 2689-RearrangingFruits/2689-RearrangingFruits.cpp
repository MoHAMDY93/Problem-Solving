// Last updated: 6/10/2026, 7:15:51 PM
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int m = INT_MAX;
        unordered_map<int , int> freq;
        for(auto i : basket1) freq[i]++ , m = min(m , i);
        for(auto i : basket2) freq[i]-- , m = min(m , i);
        vector<int> tmp;
        for(auto [k , v] : freq) {
            if(v & 1) return -1;
            for(int i=0 ; i<abs(v) / 2 ; i++) tmp.push_back(k);
        }
        nth_element(tmp.begin(), tmp.begin() + tmp.size()/2, tmp.end());
        long long cost = 0;
        for(int i=0 ; i < tmp.size() / 2 ; i++) {
            cost += min(m * 2, tmp[i]);
        }
        return cost;
    }
};