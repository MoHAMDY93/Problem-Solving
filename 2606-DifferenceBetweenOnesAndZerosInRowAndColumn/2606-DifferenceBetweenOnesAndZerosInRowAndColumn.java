// Last updated: 6/10/2026, 7:16:15 PM
class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int rows = grid.length , cols = grid[0].length;
        int[][] Rows = new int[rows][2];
        int[][] Cols = new int[cols][2];
        for(int i=0 ; i<rows ; i++) {
            int cnt = 0;
            for(int j=0 ; j<cols ; j++) {
                cnt += (grid[i][j] == 1 ? 1 : 0);
            }
            Rows[i][0] = cnt; Rows[i][1] = cols - cnt;
            System.out.print("ROWS\n");
            System.out.print(i + " " + cnt + "\n"); 
        }
        for(int j=0 ; j<cols ; j++) {
            int cnt = 0;
            for(int i=0 ; i<rows ; i++) {
                cnt += (grid[i][j] == 1 ? 1 : 0);
            }
            Cols[j][0] = cnt; Cols[j][1] = rows - cnt;
            System.out.print("COLS\n");
            System.out.print(j + " " + cnt + "\n");
        }
        int[][] res = new int[rows][cols];
        for(int i=0 ; i<rows ; i++) {
            for(int j=0 ; j<cols ; j++) {
                res[i][j] = Rows[i][0] + Cols[j][0] - Rows[i][1] - Cols[j][1];
            }
        }
        return res;
    }
}