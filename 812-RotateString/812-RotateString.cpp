// Last updated: 6/10/2026, 7:23:33 PM
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        s += s;
        return s.find(goal) != string::npos;
    }
};