class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>dp(n,0);

        dp[0] = nums[0];

        if(n==1)
        {
            return dp[0];
        }

        for(int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-1] + nums[i],nums[i]);
        } 

        int ans = *max_element(dp.begin(),dp.end());
        return ans;
    }
};
