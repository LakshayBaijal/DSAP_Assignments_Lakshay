class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>vis(m,vector<int>(n,-1));
        int minimum = INT_MAX;
        for(int j=0;j<n;j++)
        {
            int ans = pathtotal(matrix,m-1,j,vis);
            minimum = min(ans,minimum);
        }
        return minimum;
    }

    int pathtotal(vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&vis)
    {
        if(i==0)
        {
            return matrix[0][j];
        }

        if(i<0 || j<0 || j>=matrix[0].size())
        {
            return INT_MAX;
        }

        if(vis[i][j] != -1)
        {
            return vis[i][j];
        }

        int left = INT_MAX;
        int right = INT_MAX;
        int center = INT_MAX;
        if(j-1>=0)
        {
            left = pathtotal(matrix,i-1,j-1,vis);
        }

        center = pathtotal(matrix,i-1,j,vis);
        if(j+1<matrix[0].size())
        {
            right = pathtotal(matrix,i-1,j+1,vis);
        }

        int current;
        current = min(left,center);
        current = min(current,right);

        if(current!=INT_MAX)
        {
            current = current + matrix[i][j];
            vis[i][j] = current;
        }

        return current;
    }
};
