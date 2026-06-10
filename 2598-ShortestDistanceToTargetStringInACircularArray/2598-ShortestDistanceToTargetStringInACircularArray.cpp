// Last updated: 6/10/2026, 7:16:17 PM
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX;
        int n = words.size();
        for (int i=0 ; i<n ; i++) {
            if (words[i] == target)
                ans = min({ans , (i - startIndex + n) % n , (startIndex - i + n) % n});
        }
        return ans == INT_MAX ? -1 : ans;
    }
};