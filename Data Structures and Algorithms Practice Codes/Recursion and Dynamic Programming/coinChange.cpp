class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        if(n == 0) return -1;
        vector<vector<int>>vis(n,vector<int>(amount+1,-1));

        int ans = coinscount(vis,coins,n-1,amount);
        return ans > amount ? -1:ans;
    }

    int coinscount(vector<vector<int>>&vis,vector<int>&coins,int index,int amount)
    {
        if(amount == 0)
        {
            return 0;
        }
        if(index < 0)
        {
            return amount+1;
        }

        if(index ==0){
            if(amount % coins[0] ==0){
                return amount / coins[0];
            }
            else{
                return amount+1;
            }
        }

        if(vis[index][amount] != -1)
        {
            return vis[index][amount];
        }
        int pick = amount+1;
        int notpick = amount+1;
        if(amount >= coins[index])
        {
            pick = coinscount(vis,coins,index,amount-coins[index]) + 1;
        }
        notpick = coinscount(vis,coins,index-1,amount);

        int current = min(pick,notpick);
        vis[index][amount] = current;
        return current;
    }
};
