class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>>vis(m,vector<int>(n,-1));


        int ans = totalpath(triangle,0,0,vis);
        return ans; 
    }

    int totalpath(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>& vis)
    {
        int m = triangle.size();
        if(i==m-1)
        {
            return triangle[m-1][j];
        }

        if(i>=m || j>= triangle[i].size())
        {
            return INT_MAX;
        }

        if(vis[i][j]!=-1)
        {
            return vis[i][j];
        }

        int left = totalpath(triangle,i+1,j,vis);
        int right = totalpath(triangle,i+1,j+1,vis);

        int current = min(left,right) + triangle[i][j];
        vis[i][j] = current;
        return current;
    }
};
