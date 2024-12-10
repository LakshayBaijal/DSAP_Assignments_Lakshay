public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) 
    {
        // Your code here
        // return vector with correct order of elements
        vector <int> cross;
        int n1 = a.size();
        int n2 = b.size();
        
        int i=0,j=0;
        
        while(i<n1 && j<n2)
        {
            if(a[i]<=b[j])
            {
                if(cross.empty() || cross.back()!=a[i])
                {
                    cross.push_back(a[i]);
                }
                i++;
            }
            else
            {
                if(cross.empty() || cross.back()!=b[j])
                {
                    cross.push_back(b[j]);
                }
                j++;
            }
        }
        
        while(j<n2)
        {
            if(cross.back()!=b[j])
            {
                cross.push_back(b[j]);
            }
            j++;
        }
        while(i<n1)
        {
            if(cross.back()!=a[i])
            {
                cross.push_back(a[i]);
            }
            i++;
        }
        
        return cross;
        
    }
