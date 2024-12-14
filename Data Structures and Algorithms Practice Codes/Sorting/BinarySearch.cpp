class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size()-1;
        int index=-1;
        binarysearch(nums,target,left,right,index);    
        return index;
    }

    void binarysearch(vector<int>& nums, int target,int left,int right,int &index)
    {
        if(left>right)
        {
            return;
        }
        int mid = (left + right)/2;

        if(nums[mid]==target)
        {
            index=mid;
            return;
        }
        else if(nums[mid]>target)
        {
            binarysearch(nums,target,left,mid-1,index);
            return;
        }
        else if(nums[mid]<target)
        {
            binarysearch(nums,target,mid+1,right,index);
            return;
        }
        return;
    }

};
