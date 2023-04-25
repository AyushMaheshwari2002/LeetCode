/*  You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze,
    where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.
    In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find 
    the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.
    Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

          Example 1:
                Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
                Output: 1
                Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
                Initially, you are at the entrance cell [1,2].
                - You can reach [1,0] by moving 2 steps left.
                - You can reach [0,2] by moving 1 step up.
                It is impossible to reach [2,3] from the entrance.
                Thus, the nearest exit is [0,2], which is 1 step away.

          Example 2:
                Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
                Output: 2
                Explanation: There is 1 exit in this maze at [1,2].
                [1,0] does not count as an exit since it is the entrance cell.
                Initially, you are at the entrance cell [1,0].
                - You can reach [1,2] by moving 2 steps right.
                Thus, the nearest exit is [1,2], which is 2 steps away.

          Example 3:
                Input: maze = [[".","+"]], entrance = [0,0]
                Output: -1
                Explanation: There are no exits in this maze.
*/



class Solution {
public:
    vector<int>rowDir = {-1, 1, 0, 0};
    vector<int>colDir = {0, 0, -1, 1};

    bool border(vector<vector<char>>&maze, int row, int col)
    {
        if((row == 0) || (row == maze.size() - 1)) 
            return true;
        
        if((col == 0) || (col == maze[0].size() - 1))
            return true;
        
        return false;
    }
    bool ValStep(vector<vector<char>>&maze, int& row, int& col)
    {
        int m = maze.size(), n = maze[0].size();

        if(row < 0 || row == m || col < 0 || col == n || maze[row][col] == '+') 
            return false;
        
        else    
            return true;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
     {
        queue<pair<int, int>>q;
        q.push({entrance[0], entrance[1]});
        int path = 0;

        maze[entrance[0]][entrance[1]] = '+'; 

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop(); 

                for(int dir = 0; dir < 4; dir++) 
                {
                    int newRow = row + rowDir[dir];  
                    int newCol = col + colDir[dir];

                    if(ValStep(maze, newRow, newCol))
                    {
                        maze[newRow][newCol] = '+';
                        
                        if(border(maze, newRow, newCol)) 
                            return (path + 1); 
                        
                        else 
                            q.push({newRow, newCol});
                    }
                }
            }
            path++; 
        }

        return -1;
    }
};




