// Last updated: 6/10/2026, 7:20:26 PM
class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';
        int l = (1 << n) - 1;
        int mid = l / 2 + 1;
        if(k == mid) return '1';
        if(k < mid)
            return findKthBit(n-1 , k);
        else 
            return findKthBit(n-1 , l - k + 1) == '1' ? '0' : '1';
    }      
};