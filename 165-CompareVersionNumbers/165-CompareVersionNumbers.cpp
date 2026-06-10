// Last updated: 6/10/2026, 7:26:13 PM
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size() , m = version2.size(); 
        int left = 0 , right = 0;
        while(left < n || right < m) {
            string L , R;
            while(left < n && version1[left] == '.') left++;
            while(left < n && version1[left] != '.') L.push_back(version1[left++]);
            
            while(right < m && version2[right] == '.') right++;
            while(right < m && version2[right] != '.') R.push_back(version2[right++]);
            
            cout << L << ' ' << R << '\n';
            if(L.empty() && R.empty()) break;
            else if(L.empty()) L = "0";
            else if(R.empty()) R = "0";
            cout << stoi(L) << ' ' << stoi(R) << "\n";
            if(stoi(L) < stoi(R)) return -1;
            else if(stoi(L) > stoi(R)) return 1;
        }
        return 0;
    }
};