// Last updated: 6/10/2026, 7:19:55 PM
class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        Deque<Integer> queue = new LinkedList<>();
        int idx = 0;
        int circles = 0 , sqaures = 0;
        for (var i : students) {
            queue.add(i);
            if (i == 0) circles++;
            else sqaures++;
        }
        while (!queue.isEmpty()) {
            if (queue.peek() == sandwiches[idx]) {
                if (sandwiches[idx] == 0) circles--;
                else sqaures--;
                idx++;
                queue.remove();
            } else if (sandwiches[idx] == 0) {
                if (circles == 0) {
                    return sqaures; 
                } else {
                    queue.add(queue.remove());
                }
            } else {
                if (sqaures == 0) return circles;
                else queue.add(queue.remove());
            }
        }
        return 0;
    }   
}