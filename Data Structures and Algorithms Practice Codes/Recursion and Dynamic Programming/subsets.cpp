class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int index = nums.size()-1;
        vector<vector<int>> subset;
        vector<int> current;

        findingsubset(subset,nums,current,index);
        return subset;
    }

    void findingsubset(vector<vector<int>>&subset,vector<int>&nums,vector<int>&current,int index)
    {
        if(index<0)
        {
            subset.push_back(current);
            return;
        }


        if(index>=0)
        {
        current.push_back(nums[index]);
        findingsubset(subset,nums,current,index-1);
        current.pop_back();
        findingsubset(subset,nums,current,index-1);
        }


        return;
    }
};
