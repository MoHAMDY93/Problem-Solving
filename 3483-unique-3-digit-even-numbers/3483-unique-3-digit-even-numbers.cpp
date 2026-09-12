class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<array<int , 3>> vis;
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                for (int k=0 ; k<n ; k++) {
                    if (i != j && i != k && j != k) {
                        if (digits[i] != 0 && digits[k] % 2 == 0) vis.insert({digits[i] , digits[j] , digits[k]});
                    }
                }
            }
        }
        return vis.size();
    }
};