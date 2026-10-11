class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0 , r = sqrt(c);
        while (l <= r) {
            long long curr = l * l + r * r;
            if (curr == c) return true;
            if (curr > c) r--;
            else l++;
        }
        return false;
    }
};