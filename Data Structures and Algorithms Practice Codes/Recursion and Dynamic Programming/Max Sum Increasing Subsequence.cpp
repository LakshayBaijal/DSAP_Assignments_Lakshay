    int maxSumIS(vector<int>& arr) 
    {
        // Your code goes here
        
        int n = arr.size();
        vector<int> dp(n+1,0);
        dp[0] = arr[0];
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j])
                {
                    dp[i] = max(dp[i],dp[j]); 
                }
            }
            dp[i] = dp[i] + arr[i];
        }
        
        int ans = *max_element(dp.begin(),dp.end());
        return ans;
    }
