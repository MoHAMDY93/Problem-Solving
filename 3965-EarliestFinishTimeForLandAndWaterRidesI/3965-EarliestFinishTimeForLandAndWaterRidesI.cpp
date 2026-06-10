// Last updated: 6/10/2026, 7:10:58 PM
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int n = landStartTime.size() , m = waterStartTime.size();
        vector<pair<int , int>> land(n) , water(m);
        for (int i=0 ; i<n ; i++) land[i] = {landStartTime[i] , landDuration[i]};
        for (int i=0 ; i<m ; i++) water[i] = {waterStartTime[i] , waterDuration[i]};
        sort(land.begin() , land.end());
        sort(water.begin() , water.end());
        vector<int> mn_land(n) , mn_water(m);
        for (int i=0 ; i<n ;i++) {
            mn_land[i] = land[i].second;
            if (i-1 >= 0) mn_land[i] = min(mn_land[i] , mn_land[i-1]); 
        }
        for (int i=0 ; i<m ;i++) {
            mn_water[i] = water[i].second;
            if (i-1 >= 0) mn_water[i] = min(mn_water[i] , mn_water[i-1]); 
        }
        vector<int> end_land(n) , end_water(m);
        for (int i=n-1 ; i>=0 ;i--) {
            end_land[i] = land[i].first + land[i].second;
            if (i+1 < n) end_land[i] = min(end_land[i] , end_land[i+1]);
        }
        for (int i=m-1 ; i>=0 ;i--) {
            end_water[i] = water[i].first + water[i].second;
            if (i+1 < m) end_water[i] = min(end_water[i] , end_water[i+1]);
        }
        // Now we mn duration for each land and water rides
        // and we have the suff mn end time for each too
        // we start get the mid point -> lower_bound on the start + end of curr ride
        // and for the other list we check two options either mn duration of prev or mn end for next
        int mn = INT_MAX;
        // start with land
        for (int i=0 ; i<n ; i++) {
            int endTime = land[i].first + land[i].second;
            auto it = upper_bound(water.begin() , water.end() , make_pair(endTime , -1));
            if (it != water.begin())
                mn = min(mn , endTime + mn_water[it - water.begin() - 1]);
            if (it != water.end()) {
                mn = min(mn , end_water[it - water.begin()]);
            }
        }
        // start with water
        for (int i=0 ; i<m ; i++) {
            int endTime = water[i].first + water[i].second;
            auto it = upper_bound(land.begin() , land.end() , make_pair(endTime , -1));
            if (it != land.begin())
                mn = min(mn , endTime + mn_land[it - land.begin() - 1]);
            if (it != land.end()) {
                mn = min(mn , end_land[it - land.begin()]);
            }
        }

        return mn;
    }
};