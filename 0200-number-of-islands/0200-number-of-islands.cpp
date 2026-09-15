class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& visit, vector<vector<char>>& grid, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || visit[i][j] || grid[i][j] != '1'){
            return;
        }

        visit[i][j]=true;

        dfs(i-1, j, visit, grid, n, m);  //top
        dfs(i, j+1, visit, grid, n, m);  //right
        dfs(i+1, j, visit, grid, n, m); //bottom
        dfs(i, j-1, visit, grid, n, m);  //left
        
    } 
    int numIslands(vector<vector<char>>& grid) {
        int island=0;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>>visit(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !visit[i][j]){
                    dfs(i, j, visit, grid, n, m);
                    island++;
                }
            }
        }
        return island;
    }
};