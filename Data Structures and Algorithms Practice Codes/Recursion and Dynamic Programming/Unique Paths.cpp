class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>vis(m,vector<int>(n,-1));

        int ans =  paths(m-1,n-1,vis);      
        return ans;
    }
    int paths(int i,int j, vector<vector<int>> &vis)
    {
        if(i<0 || j<0)
        {
            return 0;
        }
        if(i==0 && j==0)
        {
            return 1;
        }
        if(vis[i][j] != -1)
        {
            return vis[i][j];
        }

        int top = paths(i-1,j,vis);
        int left = paths(i,j-1,vis);
        vis[i][j] = top + left;
        return vis[i][j];
    }
};
