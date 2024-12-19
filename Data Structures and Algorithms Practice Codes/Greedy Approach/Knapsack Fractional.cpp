 struct Item {
        int value;
        int weight;
        double density;
    };
    
    static bool cmp(const Item& a, const Item& b) {
        return a.density > b.density;
    }
    
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) 
    {
        int n = val.size();
        vector<Item> items(n);
        
        for(int i = 0; i < n; i++)
        {
            items[i].value = val[i];
            items[i].weight = wt[i];
            if(wt[i] != 0)
                items[i].density = static_cast<double>(val[i]) / wt[i];
            else
                items[i].density = 0.0; 
        }
        
        sort(items.begin(), items.end(), cmp);
        
        int index = 0;
        double totalValue = 0.0;
        
        while(capacity > 0 && index < n)
        {
            if(capacity >= items[index].weight)
            {
                capacity -= items[index].weight;
                totalValue += items[index].value;
            }
            else
            {
                double fraction = static_cast<double>(capacity) / items[index].weight;
                totalValue += items[index].value * fraction;
                capacity = 0; 
            }
            index++;
        }
        
        return totalValue;
    }
