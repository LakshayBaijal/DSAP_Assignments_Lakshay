    int minimizeCost(int k, vector<int>& arr) 
    {
        // Code here
        int n = arr.size();
        vector<int>dp(n,0);
        vector<int>jump(k+1,10000);
        
        dp[0] = 0;

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(j<=i)
                {
                    jump[j] = dp[i-j] + abs(arr[i] - arr[i-j]);
                }
            }
            
            dp[i] = *min_element(jump.begin(),jump.end());
        }
        return dp[n-1];

    }
