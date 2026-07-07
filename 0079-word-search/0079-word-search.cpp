class Solution {
public:
    int m, n;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool dfs(vector<vector<char>> &board,
             int row,
             int col,
             int index,
             const string &word)
    {
        // Entire word matched
        if(index == word.size())
            return true;

        // Invalid cell
        if(row < 0 || col < 0 || row >= m || col >= n)
            return false;

        // Character mismatch or already visited
        if(board[row][col] != word[index])
            return false;

        // Mark visited
        char temp = board[row][col];
        board[row][col] = '#';

        // Explore 4 directions
        for(int k = 0; k < 4; k++)
        {
            int newRow = row + dx[k];
            int newCol = col + dy[k];

            if(dfs(board, newRow, newCol, index + 1, word))
            {
                board[row][col] = temp;
                return true;
            }
        }

        // Backtrack
        board[row][col] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        m = board.size();
        n = board[0].size();

        if(word.size() > m * n)
            return false;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == word[0] &&
                   dfs(board, i, j, 0, word))
                {
                    return true;
                }
            }
        }

        return false;
    }
};