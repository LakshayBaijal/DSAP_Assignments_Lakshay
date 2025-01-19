class Solution {
public:
    int jump(vector<int>& nums) 
    {
        if(nums.size() == 1)
        {
            return 0;
        }
        int ans = game(nums);  
        return ans;
    }

    int game(vector<int>&nums)
    {
        int ans = 0;
        int end = 0;
        int farthest = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            farthest = max(farthest,i+nums[i]);

            if(farthest >= nums.size() - 1)
            {
                ans++;
                break;
            }
            if(end == i)
            {
                ans++;
                end = farthest;
            }
        }
        return ans;
    }
};
