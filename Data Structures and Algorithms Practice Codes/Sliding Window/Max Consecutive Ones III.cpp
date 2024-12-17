class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int size = nums.size();
        int left=0,right=0;
        int zeros = 0;
        int len=0;
        int max_len=0;
        for(right=0;right<size;right++)
        {
            if(zeros<=k)
            {
                if(nums[right]==0)
                {
                    zeros++;
                }
            }
            
            while(zeros>k)
            {
                
                if(nums[left]==0)
                {
                    zeros--;
                }
                left++;
            }

            if(zeros<=k)
            {
                len = right - left + 1;
                max_len = max(len,max_len);
            }

        }
    return max_len;


    }
};
