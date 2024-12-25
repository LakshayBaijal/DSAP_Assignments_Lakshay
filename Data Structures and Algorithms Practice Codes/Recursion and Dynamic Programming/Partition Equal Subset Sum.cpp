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
            int index = nums.size() - 1; 
            bool flag = false;
            partition(nums,sum/2,index,flag);
            return flag;
        }
    }

    void partition(vector<int> &nums,int target,int index,bool &flag)
    {
        if(target==0)
        {
            flag = true;
            return;
        }

        if(target<0 || flag == true || index<0)
        {
            return;
        }

        partition(nums,target - nums[index],index - 1,flag);
        partition(nums,target,index - 1,flag);
        return;



    }

};
