class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int open = 0;
        for (auto c : s) {
            if (c == '(') open++;
            else if (c == ')') open--;
            maxi = max(maxi , open);
        }
        return maxi;
    }
};