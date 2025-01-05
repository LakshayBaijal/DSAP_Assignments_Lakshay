class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int index1 = text1.size() -1;
        int index2 = text2.size() -1;  

        vector<vector<int>> vis(index1+1,vector<int>(index2+1,-1));
                        
        int ans = maxsize(index1,index2,text1,text2,vis);
        return ans;
    }

    int maxsize(int index1,int index2,string text1, string text2,vector<vector<int>> &vis)
    {
        if(index1 < 0 || index2 < 0)
        {
            return 0;
        }

        if(vis[index1][index2]!=-1)
        {
            return vis[index1][index2];
        }

        if(text1[index1] == text2[index2])
        {            
            return vis[index1][index2] = 1 + maxsize(index1-1,index2-1,text1,text2,vis);
        }
        else
        {
            return vis[index1][index2] = 0 + max(maxsize(index1-1,index2,text1,text2,vis),maxsize(index1,index2-1,text1,text2,vis));
        }
    }
};
