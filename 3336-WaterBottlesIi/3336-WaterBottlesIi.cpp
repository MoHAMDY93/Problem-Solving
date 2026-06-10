// Last updated: 6/10/2026, 7:14:11 PM
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles >= numExchange) {
            ans++ , numBottles -= (numExchange-1);
            numExchange++;
            // int div = numBottles / numExchange , rem = numBottles % numExchange; 
            // ans += div;
            // numBottles = div + rem;
        }
        return ans;
    }
};