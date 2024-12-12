    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>dp(n,0); 

        dp[0]=0;
        if(nums[0]>=0)
        {
            dp[0]=nums[0];
        }

        for(int i = 1 ; i < n ; i++)
        {

            if(dp[i-1] + nums[i]>0)
            {
                dp[i] = dp[i-1] + nums[i];
            }
        }   
        int max=0;
        for(auto it:dp)
        {
            if(max < it )
            {
                max = it;
            }
        }

        return max;
    }
};
