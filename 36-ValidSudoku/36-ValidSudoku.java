// Last updated: 6/10/2026, 7:27:39 PM
class Solution {
    public boolean isValidSudoku(char[][] board) {
        int[] row = new int[9];
        int[] col = new int[9];
        int[] sub = new int[9];
        
        for (int i=0 ; i<9 ; i++) {
            for (int j=0 ; j<9 ; j++) {
                char c = board[i][j];
                if (c == '.') continue;                
                int bit = (1 << (c - '0'));
                int box = (i / 3) * 3 + (j / 3);
                if (((row[i] & bit) != 0) || ((col[j] & bit) != 0) || (sub[box] & bit) != 0) return false;
                row[i] |= bit;
                col[j] |= bit;
                sub[box] |= bit;    
            }
        }
        return true;
    }
}