class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>dp(n+1,1);
        for(int i = 1; i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i] = max(dp[j]+1,dp[i]);
                }
            }
        }

        int max = *max_element(dp.begin(),dp.end());\
        return max;
    }
};
