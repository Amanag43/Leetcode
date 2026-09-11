class Solution {
public:
    // Checks if it's safe to place a Queen at board[row][col]
    bool isSafe(int row, int col, const vector<string>& board, int n) {
        int duprow = row;
        int dupcol = col;

        // Check upper diagonal on the left
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        // Check the same row on the left
        col = dupcol;
        row = duprow;
        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }

        // Check lower diagonal on the left
        row = duprow;
        col = dupcol;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
        // Base case: If all columns are filled, add the board to the answer
        if (col == n) {
            ans.push_back(board);
            return;
        }

        // Try placing a Queen in each row of the current column
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';       // Place the Queen
                solve(col + 1, board, ans, n); // Recur for the next column
                board[row][col] = '.';       // Backtrack: Remove the Queen
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        
        // Initialize the board with empty strings of dots
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        
        solve(0, board, ans, n);
        
        return ans;
    }
};