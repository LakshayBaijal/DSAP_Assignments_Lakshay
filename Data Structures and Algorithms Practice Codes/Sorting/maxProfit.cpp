class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int i,j,max_profit=0,index;
        int n = prices.size();
        int max=0,min=INT_MAX;
        int diff=0;
        int maxdiff=0;
        for(int i=0;i<n;i++)
        {
            if(prices[i]<min)
            {
                min = prices[i];
                index = i;
                max = 0;
                for(int j=index+1;j<n;j++)
                {
                    if(max<prices[j])
                    {
                        max=prices[j];
                        diff = max - min;
                    }
                }

                if(maxdiff<=diff)
                {
                    maxdiff=diff;
                }
            }

        }

        return maxdiff;
    }
};
