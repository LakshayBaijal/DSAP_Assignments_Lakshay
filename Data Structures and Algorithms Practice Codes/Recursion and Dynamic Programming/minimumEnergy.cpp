   int minimumEnergy(vector<int>& height, int n) 
    {
        // Code here
        vector<int>dp(n+1,0);
        
        dp[0]=0;
        dp[1]= abs(height[1] - height[0]);
        int jump0,jump1;
        for(int i=2;i<=n;i++)
        {
            jump0 = abs(height[i]-height[i-1]) + dp[i-1];
            jump1 = abs(height[i]-height[i-2]) + dp[i-2];
            
            dp[i] = min(jump0,jump1);
        }
        return dp[n];
    }
