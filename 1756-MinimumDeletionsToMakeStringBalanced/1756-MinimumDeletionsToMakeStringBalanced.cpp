// Last updated: 6/10/2026, 7:20:07 PM
class Solution {
public:
    int minimumDeletions(string s) {
        int bCount = 0;
        int deletions = 0;

        for(char c : s) {
            if(c == 'b') {
                bCount++;
            } else { // 'a'
                deletions = min(deletions + 1, bCount);
            }
        }

        return deletions;
    }
};
