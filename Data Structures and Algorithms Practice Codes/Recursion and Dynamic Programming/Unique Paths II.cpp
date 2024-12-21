class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();    
        if(n==0 && m==0)
        {
            return 0;
        }
        if(n==1 && m==1)
        {
            if(obstacleGrid[0][0]==1)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        vector<vector<int>>vis(m,vector<int>(n,-1));

        return path(obstacleGrid,m-1,n-1,vis);
    }

    int path(vector<vector<int>>& obstacleGrid,int i,int j,vector<vector<int>>& vis)
    {
        if(i==0&&j==0)
        {
            return 1;
        }
        if(i<0 || j<0 || obstacleGrid[i][j]==1)
        {
            return 0;
        }
        if(vis[i][j]!=-1)
        {
            return vis[i][j];
        }
    int top=0;
    int left=0;
    if(i-1>=0)
    {
        if(obstacleGrid[i-1][j]==0)
        {
            top = path(obstacleGrid,i-1,j,vis);
        }
    }
    if(j-1>=0)
    {
        if(obstacleGrid[i][j-1]==0)
        {
            left = path(obstacleGrid,i,j-1,vis);
        }
    }

        vis[i][j] = top + left;
        return vis[i][j];
    }
};
