// Last updated: 6/10/2026, 7:20:39 PM
class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - (low / 2);
    }
};