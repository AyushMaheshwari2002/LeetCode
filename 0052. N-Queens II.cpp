/*  The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
    Given an integer n, return the number of distinct solutions to the n-queens puzzle.

          Example 1:
                Input: n = 4
                Output: 2
                Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

          Example 2:
                Input: n = 1
                Output: 1
*/



class Solution {
public:
    
    bool isSafe(int row, int col, vector<string> board)
    {
        int duprow = row;
        int dupcol = col;
        
        while(row >= 0 && col >= 0)
        {
            if(board[row][col] == 'Q')
                return false;
            --row;
            --col;
        }
        
        col = dupcol;
        row = duprow;
        while(col >= 0)
        {
            if(board[row][col] == 'Q')
                return false;
            --col;
        }
        
        row = duprow;
        col = dupcol;
        while(row < board.size() && col >= 0)
        {
            if(board[row][col] == 'Q')
                return false;
            ++row;
            --col;
        }
        return true;
    }
    
    int NQueens(int col, vector<string>& board)
    {
        if(col == board.size())
            return 1;
        
        int cnt = 0;
        
        for(int row = 0; row < board.size(); ++row)
        {
            if(isSafe(row,col,board)){
                board[row][col] = 'Q';
                cnt += NQueens(col + 1, board);
                board[row][col] = '.';
            }
        }
        return cnt;
    }
    
    
    int totalNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        
        for(int i = 0; i<n; ++i)
        {
            board[i] = s;
        }
        
        return NQueens(0,board);
    }
};



