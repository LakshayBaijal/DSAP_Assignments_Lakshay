class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,-1));
    
        int ans = path(grid,m-1,n-1,vis);
        return ans;
    }

    int path(vector<vector<int>> &grid,int i,int j,vector<vector<int>>&vis)
    {
        if(i==0 && j==0)
        {
            return grid[0][0];
        }
        if(i<0 || j<0)
        {
            return INT_MAX;
        }
        if(vis[i][j] != -1)
        {
            return vis[i][j];
        }

        int top = path(grid, i-1, j, vis);
        int left = path(grid, i, j-1, vis);

        int current = min(top,left) + grid[i][j];
        vis[i][j] = current;
        return current;

    }
};
