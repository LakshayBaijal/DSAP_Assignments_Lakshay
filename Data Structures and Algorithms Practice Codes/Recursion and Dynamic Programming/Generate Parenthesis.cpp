class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
            vector<string> s;
            string current = "";
            pairs(s,current,n,n);
            return s;   
    }

    void pairs(vector<string> &s,string current,int left , int right)
    {
        if(left == 0 && right == 0)
        {
            s.push_back(current);
            return;
        }
        if(left>0)
        {
            pairs(s,current + "(",left-1,right);
        }
        if(right>left)
        {
            pairs(s,current + ")",left,right-1);
        }
        return; 
    }
};
