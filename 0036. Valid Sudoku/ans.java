class Solution {
    public boolean isValidSudoku(char[][] board) {
        Set<String> st = new HashSet<>();
        for(int row=0;row<9;row++) 
        {
            for(int column = 0;column<9;column++) 
            {
                char num = board[row][column];
                if(num!='.') {
                    if( !st.add(num+"in row"+row) || 
                        !st.add(num+"in column"+column) || 
                        !st.add(num+"in block"+(row/3)+","+(column/3))) 
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}