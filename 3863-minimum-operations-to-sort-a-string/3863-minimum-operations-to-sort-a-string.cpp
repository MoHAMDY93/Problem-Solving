class Solution {
public:
    int minOperations(string s) {
        if (is_sorted(begin(s) , end(s))) return 0;
        int n = s.size();
        if (n == 2) return -1;
        char mn = *min_element(next(begin(s)) , prev(end(s)));
        char mx = *max_element(next(begin(s)) , prev(end(s)));

        if (s[0] <= s[n-1] && (mn >= s[0] || mx <= s[n-1])) 
            return 1;
        
        return s[n-1] < mn && s[0] > mx ? 3 : 2;
    }
};