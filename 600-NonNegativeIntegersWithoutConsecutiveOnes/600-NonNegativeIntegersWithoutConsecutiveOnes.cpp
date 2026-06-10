// Last updated: 6/10/2026, 7:24:23 PM
int mem[32][2][2];
class Solution {
public:
    int findIntegers(int n) {
        memset(mem , -1 , sizeof(mem));
        function<int(int , int , int)> dp = [&](int i , int prev , int t) {
            if(i < 0) return 1;
            auto &ret = mem[i][prev][t];
            if(~ret) return ret;
            ret = 0;
            int limit = (t ? ((n >> i) & 1) : 1);
            for(int b=0 ; b<=limit ; b++) {
                if(b && prev) continue;
                int nt = (t && (b == limit));
                ret += dp(i-1 , b , nt);
            }
            return ret;
        };
        return dp((int)log2(n) , 0 , 1);
    }
};