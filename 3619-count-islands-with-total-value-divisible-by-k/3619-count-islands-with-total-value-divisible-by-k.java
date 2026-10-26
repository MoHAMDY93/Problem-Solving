class Solution {
    private int[] dx = {1 , -1 , 0 , 0};
    private int[] dy = {0 , 0 , 1 , -1};
    public int countIslands(int[][] grid, int k) {
        int n = grid.length , m = grid[0].length;
        // boolean[][] vis = new boolean[n][m];
        // for (boolean[] row : vis) {
        //     Arrays.fill(row, false);
        // }
        int ans = 0;
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                if (grid[i][j] == 0) continue;
                ans += (dfs(i , j, grid, k) == 0 ? 1 : 0);
            }
        }
        return ans;
    }
    private int dfs(int i , int j, int[][] grid, int k) {
        int n = grid.length , m = grid[0].length;
        if (0 > i || i >= n || 0 > j || j >= m || grid[i][j] == 0) return 0;
        int sum = grid[i][j] % k;
        grid[i][j] = 0;
        for (int d = 0 ; d < 4 ; d++) {
            int nx = i + dx[d] , ny = j + dy[d];
            sum = (sum + dfs(nx , ny , grid, k)) % k; 
        }
        return sum;
    }
}