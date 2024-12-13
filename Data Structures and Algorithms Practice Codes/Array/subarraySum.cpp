class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int count=0;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            int sum = k;
            for(int j=i;j<n;j++)
            {
                sum = sum-nums[j];
                if(sum==0)
                {
                    count++;
                }

            }
        }
        return count;
    }


};
