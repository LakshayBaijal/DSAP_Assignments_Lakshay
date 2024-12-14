int maxLen(vector<int>& arr) 
    {
        // code here
        long long presum;
        unordered_map<long long, int> prefixSumMap;
        prefixSumMap[0] = -1;
        int prefixsum = 0;
        int max_len=0;
        for(int i=0;i<arr.size();i++)
        {
            prefixsum += arr[i];
            
            if(prefixSumMap.find(prefixsum) != prefixSumMap.end())
            {
                 int previndex = prefixSumMap[prefixsum];
                int current_len = i - previndex;
                if(current_len > max_len) {
                    max_len = current_len;
                }
        
            }
            
            else
            {
                prefixSumMap[prefixsum] = i;
            }
        }
        
        return max_len;
    }
