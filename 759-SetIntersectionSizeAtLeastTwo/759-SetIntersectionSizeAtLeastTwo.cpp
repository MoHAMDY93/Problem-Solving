// Last updated: 6/10/2026, 7:23:52 PM
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& interv) {
        sort(interv.begin() , interv.end() , [](vector<int>& X , vector<int>& Y){
            const int x0 = X[0] , x1 = X[1] , y0 = Y[0] , y1 = Y[1];
            return (x1 == y1) ? x0 > y0 : x1 < y1;
        });

        int cnt = 2 , n = interv.size();
        int b = interv[0][1] , a = b-1;
        for(int i=1 ; i<n ; i++) {
            int L = interv[i][0] , R = interv[i][1];
            if(a >= L) continue;
            bool NoIntersect = L > b;
            cnt += 1 + NoIntersect;
            a = (NoIntersect) ? R-1 : b;
            b = R;
        }
        return cnt;
    }
};