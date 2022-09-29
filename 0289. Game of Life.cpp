/*  According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in
    1970."
    The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts 
    with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
          1. Any live cell with fewer than two live neighbors dies as if caused by under-population.
          2. Any live cell with two or three live neighbors lives on to the next generation.
          3. Any live cell with more than three live neighbors dies, as if by over-population.
          4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
    The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the 
    current state of the m x n grid board, return the next state.

                Example 1:
                       Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
                       Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

                Example 2:
                       Input: board = [[1,1],[1,0]]
                       Output: [[1,1],[1,1]]
*/



class Solution {
public:
    
    int check(vector<vector<int>> v, int i, int j, int n, int m)
    {
        int ind = 0;
        if(i > 0)
        {
            if(v[i-1][j] == 1)
                ++ind;
        }
        if(j > 0)
        {
            if(v[i][j-1] == 1)
                ++ind;
        }
        if(i < m-1)
        {
            if(v[i+1][j] == 1)
                ++ind;
        }
        if(j < n-1)
        {
            if(v[i][j+1] == 1)
                ++ind;
        }
        if(i > 0 && j > 0)
        {
            if(v[i-1][j-1] == 1)
                ++ind;
        }
        if(i < m-1 && j < n-1)
        {
            if(v[i+1][j+1] == 1)
                ++ind;
        }
        if(i > 0 && j < n-1)
        {
            if(v[i-1][j+1] == 1)
                ++ind;
        }
        if(j > 0 && i < m-1)
        {
            if(v[i+1][j-1] == 1)
                ++ind;
        }
        return ind;
    }
    
    void gameOfLife(vector<vector<int>>& board)
    {
        vector<vector<int> > v = board;
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i<m; ++i)
        {
            for(int j = 0; j<n; ++j)
            {
                int ind = check(v,i,j,n,m);
                if(board[i][j] == 0)
                {
                       if(ind == 3)
                           board[i][j] = 1;
                }
                else
                {
                       if(ind < 2 || ind > 3)
                           board[i][j] = 0;
                }
            }
        }    
    }
};



