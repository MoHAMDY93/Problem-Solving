// Last updated: 6/10/2026, 7:19:54 PM
class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.begin() , n.end()) - '0';
    }
};