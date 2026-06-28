// Last updated: 6/28/2026, 5:18:43 AM
// Easy Sorting problem, U should only keep tracking of the diff between any two adjacent elements (donn make it > 1)
1class Solution {
2public:
3    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
4        cout << arr.size() << '\n';
5        sort(begin(arr) , end(arr));
6        int prev = 1;
7        for (auto& i : arr) {
8            i = min(prev , i);
9            prev = i + 1;
10        }
11        return arr.back();
12    }
13};