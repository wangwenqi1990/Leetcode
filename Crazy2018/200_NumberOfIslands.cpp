class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // dfs
        if(grid.empty()||grid[0].empty()) return 0;
        int row = grid.size(), col = grid[0].size(), res=0;
        for(int i=0; i<row; i++){
            for(int j=0;j<col; j++){
                if(grid[i][j]=='1'){
                    res++;
                    dfs(grid, row, col,i,j);
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& grid, int row, int col, int i, int j){
        if(i<0 ||i>=row||j<0||j>=col||grid[i][j]=='0') return;
        grid[i][j]='0';
        update(grid, row, col, i+1,j);
        update(grid, row, col, i-1,j);
        update(grid, row, col, i,j+1);
        update(grid, row, col, i,j-1);
    }
};