    bool isSubsetSum(vector<int>& arr, int target) 
    {
        // code here
        int n = arr.size();
        vector<vector<int>>vis(n,vector<int>(target+1,-1));
        
        bool ans = subset(arr,target,n-1,vis);
        return ans;
    }
    
    bool subset(vector<int>&arr,int target,int index,vector<vector<int>>&vis)
    {
        if(target==0)
        {
            return true;
        }
        
        if(index == 0)
        {
            return target == arr[0];
        }
        if(vis[index][target]!=-1)
        {
            return vis[index][target];
        }
        
        bool pick = false;
        bool notpick = false;
        
        if(target>=arr[index])
        {
            pick = subset(arr,target - arr[index],index - 1,vis);
        }
        notpick = subset(arr,target,index - 1,vis);
        
        return vis[index][target] = pick | notpick;
    }
    
