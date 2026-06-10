// Last updated: 6/10/2026, 7:14:13 PM
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin() , apple.end() , 0);
        int cnt = 0 , curr = 0;
        // cout << sum << '\n';
        sort(capacity.rbegin() , capacity.rend());
        for(auto i : capacity) {
            if(sum > curr) curr += i , cnt++;
        }   
        return cnt;
    }
};