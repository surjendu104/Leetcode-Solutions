class Solution {
    public int snakesAndLadders(int[][] board) {
        int target = board.length * board.length;

        Queue<Integer> q = new LinkedList<>();
        boolean[] visit = new boolean[target + 1];
        q.add(1);
        visit[1] = true;

        int steps = 0;
        while (!q.isEmpty()) {
            int options = q.size();
            steps++;

            for (int i = 0; i < options; i++) {
                int currCell = q.remove();
                for (int j = 1; j < 7; j++) {
                    int nextCell = getNextIndex(board, currCell + j);
                    if (nextCell == target)
                        return steps;
                    if (!visit[nextCell]) {
                        q.add(nextCell);
                        visit[nextCell] = true;
                    }

                }
            }
        }

        return -1;
    }

    private int getNextIndex(int[][] board, int index) {
        int n = board.length;
        int row = n - 1 - (index - 1) / n;
        int col = ((index - 1) / n % 2) == 0 ? (index - 1) % n : n - 1 - (index - 1) % n;
        return board[row][col] == -1 ? index : board[row][col];
    }

}