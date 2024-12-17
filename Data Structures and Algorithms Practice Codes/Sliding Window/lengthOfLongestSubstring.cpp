    int lengthOfLongestSubstring(string s) 
    {
        int hash[256];
        int n=s.length();
        for(int i=0;i<256;i++)
        {
            hash[i] = -1;
        }    

        int left=0,right=0;
        int len=0,max_len=0;
        for(right = 0; right<n;right++)
        {
            if(hash[s[right]] != -1)
            {
                if(hash[s[right]] >= left)
                {
                    left = hash[s[right]] + 1;
                }
            }
                len = right - left + 1;

                max_len = max(len,max_len);
                hash[s[right]] = right;
            
        }

    return max_len;
    }
