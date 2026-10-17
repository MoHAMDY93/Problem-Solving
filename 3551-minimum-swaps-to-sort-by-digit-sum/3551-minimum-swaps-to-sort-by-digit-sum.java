class Solution {
    static class Element implements Comparable<Element> {
        int val, digitSum, idx;
        Element (int num , int idx) {
            this.idx = idx;
            this.val = num;
            this.digitSum = getDigitSum(num);
        }
        private static int getDigitSum(int num) {
            int sum = 0;
            for (; num > 0 ; num /= 10) {
                sum += (num % 10);
            }
            return sum;
        }
        @Override
        public int compareTo(Element other) {
            if (this.digitSum != other.digitSum) {
                return Integer.compare(this.digitSum, other.digitSum);
            }
            return Integer.compare(this.val, other.val);
        }
    }
    public int minSwaps(int[] nums) {
        int n = nums.length;
        Element[] arr = new Element[n];
        for (int i=0 ; i<n ; i++) {
            arr[i] = new Element(nums[i] , i);
        }
        Arrays.sort(arr);
        for (var e : arr) System.out.print(e.idx + " " + e.val + " " + e.digitSum + "\n");
        int ans = 0;
        boolean[] vis = new boolean[n];
        for (int i=0 ; i<n ; i++) {
            if (vis[i] == true || arr[i].idx == i) continue;
            int sz = 0 , curr = i;
            while (!vis[curr]) {
                vis[curr] = true;
                sz++;
                curr = arr[curr].idx;
            }
            ans += (sz - 1);
        }
        return ans;
    }
}