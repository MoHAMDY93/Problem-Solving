// Last updated: 6/10/2026, 7:23:24 PM
class Solution {
    static class pair {
        int first , second;
        public pair(int first , int second) {
            this.first = first;
            this.second = second;
        }

    }
    public int maxProfitAssignment(int[] d, int[] p, int[] w) {
        /*
            85  47  57
            24  66  99
            sort::
            47  57  85
            66  99  24
            now get the pref_max of the profit:
            47  57  85
            66  99  99
            This mmeans we can use binary serach to get the last one any worekr can do, 
            this way we determine the ,ax profit easily using the pref_max
        */
        int n = d.length;
        List<pair> a = new ArrayList<>();
        for(int i=0 ; i<n ; i++) {
            a.add(new pair(d[i] , p[i]));
        }
        Collections.sort(a, (p1, b) -> Integer.compare(p1.first, b.first));
        for(var it : a) {
            System.out.println(it.first + " " + it.second);
        }
        List<Integer> pref_max = new ArrayList<>();
        pref_max.add(a.get(0).second);
        for(int i=1 ; i<n ; i++) {
            pref_max.add(Math.max(pref_max.get(i-1) , a.get(i).second));
        }
        int ans = 0;
        for(var val : w) {
            int l = 0 , r = n-1 , idx = -1;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if(val >= a.get(mid).first) {
                    idx = mid;
                    l = mid+1;
                } else 
                    r = mid-1;
            }
            // System.out.println(idx + " ");
            if(idx != -1) {
                // System.out.println(pref_max.get(idx));
                ans += pref_max.get(idx);
            }
        }
        return ans;
    }
}