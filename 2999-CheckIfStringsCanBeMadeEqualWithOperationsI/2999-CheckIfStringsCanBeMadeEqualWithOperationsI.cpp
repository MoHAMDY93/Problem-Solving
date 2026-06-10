// Last updated: 6/10/2026, 7:15:06 PM
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        unordered_map<char , int> odd1 , odd2 , even1 , even2;
        for (int i=0 ; i<s1.size() ; i++) {
            (i & 1 ? odd1 : even1)[s1[i]]++;
        }
        for (int i=0 ; i<s2.size() ; i++) {
            (i & 1 ? odd2 : even2)[s2[i]]++;
        }
        if (odd1 == odd2 && even1 == even2) return true;
        return false;
    }
};