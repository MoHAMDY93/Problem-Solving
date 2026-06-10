// Last updated: 6/10/2026, 7:25:51 PM
class Solution {
    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        boolean[][] vis = new boolean[n][m];
        int[] dx = {1 , -1 , 0 , 0};
        int[] dy = {0 , 0 , 1 , -1};
        
        BiPredicate<Integer, Integer> check =
            (a, b) -> 0 <= a && a < n &&
                    0 <= b && b < m &&
                    grid[a][b] == '1' &&
                    !vis[a][b];
        int cnt = 0;
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                if (grid[i][j] == '0' || vis[i][j]) continue;
                cnt++;
                if (!vis[i][j]) {
                    Queue<int[]> q = new LinkedList<>();
                    q.add(new int[] {i , j});
                    vis[i][j] = true;
                    while (!q.isEmpty()) {
                        var pos = q.poll();
                        int x = pos[0] , y = pos[1];
                        for (int d=0 ; d<4 ; d++) {
                            int nx = x + dx[d] , ny = y + dy[d];
                            if (check.test(nx , ny)) {
                                vis[nx][ny] = true;
                                q.add(new int[] {nx , ny});
                            }
                        }
                    }
                } 
            }
        }
        return cnt;
    }
}