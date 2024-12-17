public:
    vector<string> findPath(vector<vector<int>> &mat) 
    {
        vector<string> str;
        string current="";
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        direction(str,vis,mat,current,0,0);
        return str;
    }
    
    void direction(vector<string> &str,vector<vector<int>>&vis,vector<vector<int>> &mat,string current,int row,int column)
    {
    int n = mat.size();
    int m = mat[0].size();

    if(row < 0 || row >= n || column < 0 || column >= m || mat[row][column] == 0 || vis[row][column] == 1) {
        return;
    }

    if(row == n - 1 && column == m - 1) {
        str.push_back(current);
        return;
    }

    vis[row][column] = 1;
        
     if(row + 1 < n && mat[row + 1][column] == 1 && vis[row + 1][column] == 0) {
        direction(str, vis, mat, current + 'D', row + 1, column);
    }

    if(column - 1 >= 0 && mat[row][column - 1] == 1 && vis[row][column - 1] == 0) {
        direction(str, vis, mat, current + 'L', row, column - 1); // Corrected to column -1
    }

    if(column + 1 < m && mat[row][column + 1] == 1 && vis[row][column + 1] == 0) {
        direction(str, vis, mat, current + 'R', row, column + 1);
    }

    if(row - 1 >= 0 && mat[row - 1][column] == 1 && vis[row - 1][column] == 0) {
        direction(str, vis, mat, current + 'U', row - 1, column);
    }

        
        vis[row][column]=0;

        return;
    }
