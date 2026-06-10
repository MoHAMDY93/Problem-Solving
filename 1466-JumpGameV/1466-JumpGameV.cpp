// Last updated: 6/10/2026, 7:21:15 PM
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> ord(n);
        iota(ord.begin() , ord.end() , 0);
        sort(ord.begin() , ord.end() , [&](int a , int b) {
            return arr[a] < arr[b];
        });
        vector<int> best(n , 1);
        for (int i : ord) {
            bool ok_right = true , ok_left = true;
            for (int j=1 ; j<=d ; j++) {
                if (i + j < n && ok_right) {
                    if (arr[i+j] < arr[i]) best[i] = max(best[i] , best[i+j] + 1);
                    else ok_right = false;
                }
                if (i - j >= 0 && ok_left) {
                    if (arr[i-j] < arr[i]) best[i] = max(best[i] , best[i-j] + 1);
                    else ok_left = false;
                }
            }
        }
        return *max_element(best.begin() , best.end());
    }
};