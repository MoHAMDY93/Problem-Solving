// Last updated: 6/10/2026, 7:13:38 PM
class Solution {
public:
    int minOperations(vector<int>& a) {
        int n = a.size();
        int cnt = 0;
        for(int i=0 ; i<n-2 ; i++) {
            if(a[i] == 0){
                a[i] = 1;
                a[i+1] ^= 1;
                a[i+2] ^= 1;
                cnt++;
            }
        }
        if(a[n-1] == 0 || a[n-2] == 0)
            return -1;
        return cnt;
    }   
};