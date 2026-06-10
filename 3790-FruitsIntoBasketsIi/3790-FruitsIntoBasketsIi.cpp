// Last updated: 6/10/2026, 7:12:04 PM
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size() , cnt = 0;
        vector<bool>c(n , false);
        for(int i=0 ; i<n ; i++) {
            bool done = false;
            for(int j=0 ; j<n ; j++) {
                if(baskets[j] >= fruits[i] && !c[j]){
                    c[j] = true;
                    done = true;
                    break;
                }
            }
            if(!done)
                cnt++;
        }
        return cnt;
    }
};