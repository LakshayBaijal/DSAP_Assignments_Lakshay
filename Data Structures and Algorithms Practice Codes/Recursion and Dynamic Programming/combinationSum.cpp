class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
         int index = candidates.size()-1;
         vector<vector<int>> combo;
         vector<int>current;
         comb(combo,current,candidates,target,index);  

        return combo; 
    }

    void comb(vector<vector<int>>&combo,vector<int>current,vector<int>&candidates,int target,int index)
    {
        if(target==0)
        {
            combo.push_back(current);
            return;
        }
        if(index<0 || target<0)
        {
            return;
        }

        current.push_back(candidates[index]);
        comb(combo,current,candidates,target-candidates[index],index);
        current.pop_back();
        comb(combo,current,candidates,target,index-1);
        return;
    }
};
