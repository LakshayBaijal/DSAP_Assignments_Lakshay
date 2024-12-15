class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int>current;
        vector<vector<int>>subset;
        int size=nums.size();
        int index=0;
        sort(nums.begin(),nums.end());
        sub(subset,nums,current,size,index);
        return subset;    
    }

    void sub(vector<vector<int>>&subset,vector<int>&nums,vector<int>current,int size,int index)
    {
        if(index==size)
        {
            subset.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        sub(subset,nums,current,size,index+1);
        current.pop_back();

    while(index + 1 < size && nums[index] == nums[index + 1])
        {
            index++;
        }
    sub(subset,nums,current,size,index+1);
    return;
    }
};
