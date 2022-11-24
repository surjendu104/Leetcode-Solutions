class Solution {
    static boolean DFS(char[][] board, char[] word, int i, int j, int idx) {
        if (idx == word.length)
            return true;
        if (i < 0 || i >= board.length || j < 0 || j >= board[i].length || board[i][j] != word[idx])
            return false;

        board[i][j] = '0';
        boolean status = DFS(board, word, i + 1, j, idx + 1) ||
                DFS(board, word, i, j + 1, idx + 1) ||
                DFS(board, word, i - 1, j, idx + 1) ||
                DFS(board, word, i, j - 1, idx + 1);
        board[i][j] = word[idx];
        return status;
    }

    public boolean exist(char[][] board, String word) {
        if (word.length() == 0)
            return false;
        char[] wordArray = word.toCharArray();
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == wordArray[0] && DFS(board, wordArray, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
}