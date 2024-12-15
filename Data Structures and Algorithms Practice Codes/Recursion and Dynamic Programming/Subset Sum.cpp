vector<int> subsetSums(vector<int>& arr) 
    {
        // code here
        vector<int>subset;
        int n=arr.size();
        int target=0;
        int index=0;
        subsetting(subset,index,n,target,arr);
        
        return subset;
    }
    
    void subsetting(vector<int>&subset,int index,int size,int target,vector<int>&arr)
    {
        if(index==size)
        {
            subset.push_back(target);
            return;
        }
        subsetting(subset,index+1,size,target,arr);
        subsetting(subset,index+1,size,target+arr[index],arr);

        return;
    }
