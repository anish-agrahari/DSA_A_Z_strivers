class Solution {
    vector<vector<vector<int>>> memo;
    bool searchPath(vector<vector<char>>& grid, int r, int c, int bal){
        if(grid[r][c]=='(') bal++;
        else bal--;
        if(bal<0) return false;
        int rows = grid.size();
        int cols = grid[0].size();
        if(r==rows-1 && c==cols-1) return bal==0;
        if(memo[r][c][bal]!=-1) return memo[r][c][bal];
        bool validPath = false;
        if(r+1 < rows) validPath=searchPath(grid, r+1, c, bal);
        if (!validPath && c+1< cols) validPath=searchPath(grid, r, c+1, bal);

        return memo[r][c][bal]=validPath;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (grid[0][0] == ')' || grid[rows - 1][cols - 1] == '(') {
            return false;
        }

        if ((rows + cols - 1) % 2 != 0) {
            return false;
        }

        memo.assign(rows, vector<vector<int>>(
            cols, vector<int>(rows + cols, -1)
        ));

        return searchPath(grid, 0, 0, 0);
    }
};