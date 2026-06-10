// Last updated: 6/10/2026, 7:26:45 PM
class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int sell = 0 , hold = INT_MIN;
        for(int price : prices) {
            sell = max(sell , price + hold);
            hold = max(hold , -price);
        }
        return sell;
    }
};