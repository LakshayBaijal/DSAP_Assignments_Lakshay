int getSecondLargest(vector<int> &arr) 
    {
        // Code Here
        int max=0,second_max=-1;
        
        for(auto it:arr)
        {
            if(it>max)
            {
                max=it;
            }
        }
        
        for(auto it:arr)
        {
            if(it>second_max && max!=it)
            {
                second_max=it;
            }
        }
        
        
        return second_max;
