// Last updated: 6/10/2026, 7:20:33 PM
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles >= numExchange) {
            int div = numBottles / numExchange , rem = numBottles % numExchange; 
            ans += div;
            numBottles = div + rem;
        }
        return ans;
    }
};