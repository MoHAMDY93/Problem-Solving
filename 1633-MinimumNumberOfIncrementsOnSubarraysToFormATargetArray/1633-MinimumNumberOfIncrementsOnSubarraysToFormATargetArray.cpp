// Last updated: 6/10/2026, 7:20:36 PM
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = 0 , prev = 0;
        for(int i : target) {
            if(i > prev) res += i - prev;
            prev = i;
        }
        return res;
    }
};