// Last updated: 6/10/2026, 7:23:19 PM
class car {
    int first;
    double second;
    car(int f , double s) {
        first = f;
        second = s;
    }
}
class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        int n = position.length;
        List<car> a = new ArrayList<>();
        for(int i=0 ; i<n ; i++) {
            a.add(new car(position[i] , ((double)(target - position[i]) / speed[i])));
        }
        Collections.sort(a, (c1, c2) -> Integer.compare(c2.first, c1.first)); 
        double curr = a.get(0).second;
        int cnt = 1;
        for(int i=0 ; i<n ; i++) {
            if(a.get(i).second > curr) {
                cnt++;
                curr = a.get(i).second;
            }  
        }
        return cnt;
    }
}