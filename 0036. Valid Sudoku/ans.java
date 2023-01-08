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

//Backtracking
class Solution {
    public boolean isValidSudoku(char[][] board) {
     for(int i=0;i<9;i++)
     {
         for(int j=0;j<9;j++)//traverse in bfs manner 
         {
             char ch=board[i][j];
             if(ch!='.')//if ch is apart from '.'we need to check whether the given number is verifiable
             {
                 board[i][j]='.';//change it to . so that it cannot consider itself
                 if(!isValid(board,ch,i,j))//if not verifiable
                     return false;//invalid sudoku
                 board[i][j]=ch;//after checking change it to its initial value
             }
         }
     }
        return true;
    }
    static boolean isValid(char[][]ch,char ch1,int i,int j)
    {
      for(int k=0;k<9;k++)
      {
          if(ch[i][k]==ch1)return false;//for checking row associated with it
          if(ch[k][j]==ch1)return false;//for checking column associated with it
          if(ch[3*(i/3)+k/3][3*(j/3)+k%3]==ch1)return false;//for checking block associated with it
      }
        return true;
    }
}