class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int>positive;
        vector<int>negative;
        vector<int>combined;

        for(auto num:nums)
        {
            if(num>0)
            {
                positive.push_back(num);
            }
            else
            {
                negative.push_back(num);
            }
        }
        int count=0;
        int n = nums.size();
        while(count!=n/2)
        {
            combined.push_back(positive[count]);
            combined.push_back(negative[count]);
            count++;
        }
        return combined;
    }
};
