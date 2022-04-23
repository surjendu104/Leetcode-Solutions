class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        map<char, int> m;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (m[board[i][j]])
                        return false;
                    m[board[i][j]]++;
                }
            }
            m.clear();
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] != '.')
                {
                    if (m[board[j][i]])
                        return false;
                    m[board[j][i]]++;
                }
            }
            m.clear();
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int r = i * 3; r < i * 3 + 3; r++)
                {
                    for (int l = j * 3; l < j * 3 + 3; l++)
                    {
                        if (board[r][l] != '.')
                        {
                            if (m[board[r][l]])
                                return false;
                            m[board[r][l]]++;
                        }
                    }
                }
                m.clear();
            }
        }
        return true;
    }
};