class Solution {
public:
    void solve(int col, vector<string>& board, int n,
               vector<int>& leftRow,
               vector<int>& upperDiagonal,
               vector<int>& lowerDiagonal,
               vector<vector<string>>& ans) {   // ✅ pass by reference
        
        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(leftRow[row] == 0 &&
               lowerDiagonal[row + col] == 0 &&
               upperDiagonal[n - 1 + col - row] == 0) {

                board[row][col] = 'Q';

                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                solve(col + 1, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);

                // Backtrack
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<int> leftRow(n, 0),
                    upperDiagonal(2*n - 1, 0),
                    lowerDiagonal(2*n - 1, 0);

        solve(0, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);
        return ans;
    }
};