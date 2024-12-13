class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        set<int>hash;
        int n = nums.size();

        for(auto num:nums)
        {
            hash.insert(num);
        }
        int max_count=0;
        int count=0;
        int prev;
        int flag=0;
        for(auto it:hash)
        {
            if(flag == 0 || it-prev==1)
            {
                flag = 1;
                count++;
            }
            else
            {
                count=1;
            }
            prev=it;

            if(max_count<count)
            {
                max_count = count;
            }
        }

        return max_count;
    }
};
