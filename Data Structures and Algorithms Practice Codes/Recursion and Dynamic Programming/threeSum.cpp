class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<int>current;
        vector<vector<int>>ans;
        int length = 3;
        int index = nums.size() - 1;

        sort(nums.begin(),nums.end());

        sum(ans,nums,current,length,index,0); 
        return ans;  
    }

    void sum(vector<vector<int>>&ans,vector<int>&nums,vector<int>&current,int length,int index,int total)
    {
        if(length==0 && total == 0)
        {
            ans.push_back(current);
            return;
        }
        if(index<0)
        {
            return;
        }
        current.push_back(nums[index]);
        sum(ans,nums,current,length-1,index-1,total + nums[index]);   
        current.pop_back();

        int currentCandidate = nums[index];
            while(index>0 && currentCandidate == nums[index-1])
            {
                index--;
            }
            sum(ans,nums,current,length,index-1,total);
            return;


    }
};
