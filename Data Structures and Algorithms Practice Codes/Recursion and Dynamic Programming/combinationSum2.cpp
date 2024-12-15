class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        int size=candidates.size();
        vector<vector<int>> combo;
        vector<int> current;
        sort(candidates.begin(),candidates.end());
        comb(combo,candidates,current,target,0,size);
        return combo;
    }

    void comb(vector<vector<int>> &combo,vector<int>& candidates,vector<int>& current,int target,int index,int size)
    {
        if(target==0)
        {
            combo.push_back(current);
            return;
        }
        if(target<0 || index >= size)
        {
            return;
        }

        current.push_back(candidates[index]);
            comb(combo,candidates,current,target-candidates[index], index+1, size);
        current.pop_back();

        while(index + 1 < size && candidates[index] == candidates[index + 1])
        {
            index++;
        }
        comb(combo,candidates,current,target,index+1,size);
        return;
    }
};
