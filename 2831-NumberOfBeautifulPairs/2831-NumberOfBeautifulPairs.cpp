// Last updated: 6/10/2026, 7:15:31 PM
class Solution {
public:
    int getFirst(int x) {
        int d = -1;
        while(x > 0) {
            d = x % 10;
            x /= 10;
        }
        return d;
    }
    int countBeautifulPairs(vector<int>& nums) {
        int cnt = 0 , n = nums.size();
        vector<int> firstDigit(10 , 0);
        for(int num : nums) {
            int dLast = num % 10;
            for(int i=1 ; i<10 ; i++) {
                if(gcd(dLast , i) == 1) cnt += firstDigit[i];
            }
            firstDigit[getFirst(num)]++;
        }
        return cnt;
    }
};