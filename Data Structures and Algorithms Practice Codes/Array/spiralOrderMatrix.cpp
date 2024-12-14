class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector <int> output;

        int n = matrix.size();
        int m = matrix[0].size();

        int top=0,bottom=n-1,left=0,right=m-1;

        while(top<=bottom && left<=right)
        {
            for(int i=left;i<=right;i++)
            {
                output.push_back(matrix[top][i]);
            }
            top++;

            for(int i=top;i<=bottom;i++)
            {
                output.push_back(matrix[i][right]);
            }
            right--;
        
        if(top <= bottom)
        {
            for(int i=right;i>=left;i--)
            {
                output.push_back(matrix[bottom][i]);
            }
            bottom--;

        }
        if(left<=right)
        {
            for(int i=bottom;i>=top;i--)
            {
                output.push_back(matrix[i][left]);
            }
            left++;
        }

        }   

        return output;
    }
};
