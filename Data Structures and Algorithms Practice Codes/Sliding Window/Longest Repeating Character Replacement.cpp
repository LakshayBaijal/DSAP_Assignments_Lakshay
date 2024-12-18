class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int max_len=0;
        for(char c='A';c<='Z';c++)
        {
            int left=0,right=0;
            int replacement=0;
            int len=0;

            for(right=0;right<s.length();right++)
            {
                if(s[right]!=c)
                {
                    replacement++;
                    

                    while(replacement>k)
                    {
                        if(s[left]!=c)
                        {
                            replacement--;
                        }
                    left++;

                    }
                }
                len=right-left+1;
                max_len=max(len,max_len);
            }
        }    
            return max_len;

    }


};
