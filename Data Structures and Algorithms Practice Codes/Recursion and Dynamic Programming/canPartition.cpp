class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = 0;
        for(auto it:nums)
        {
            sum = sum + it;
        }

        if(sum%2!=0)
        {
            return false;
        }
        else
        {
            int n = nums.size(); 
            vector<vector<int>>vis(n,vector<int>(sum/2+1,-1));
            bool ans = subset(nums,vis,sum/2,n-1);
            return ans;
        }
    }

    bool subset(vector<int>&nums,vector<vector<int>>&vis,int target,int index)
    {
        if(target==0)
        {
            return true;
        }
        if(index == 0)
        {
            return target == nums[0];
        }

        if(vis[index][target]!=-1)
        {
            return vis[index][target];
        }

        bool pick = false;
        bool notpick = false;

        notpick =  subset(nums,vis,target,index-1);
        if(target>=nums[index])
        {
            pick = subset(nums,vis,target - nums[index],index-1);
        }

        return vis[index][target] = (pick | notpick);
    }

};
