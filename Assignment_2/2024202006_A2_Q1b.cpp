#include <iostream>
#include <vector>

using namespace std;

typedef long long ull;

size_t custom_hash(ull key) 
{
    return key % 50000; 
}

struct CustomMap 
{
    vector<pair<ull, ull>> data;

    bool insert_or_update(ull key, ull value) 
    {
        for (auto &p : data) 
        {
            if (p.first == key) 
            {

                p.second = value;  
                return true;       
            }
        }
        data.push_back({key, value});  
        return false;                 
    }

    ull get(ull key) 
    {
        for (const auto &p : data) 
        {
            if (p.first == key) 
            {
                return p.second;  
            }
        }
        return 0;  
    }
};

int main() {
    int t;
    cin >> t;  
    while (t--) 
    {
        ull n;
        cin >> n;  

        vector<CustomMap> table(50000);

        while (n--) 
        {
            int type;
            ull k, v;
            cin >> type >> k;

            if (type == 0) 
            {  
                cin >> v;
                size_t idx = custom_hash(k);
                if (table[idx].insert_or_update(k, v)) 
                {
                    cout << "1" << endl;  
                } 
                else 
                {
                    cout << "0" << endl;  
                }
            } 
            else if (type == 1) 
            {  
                size_t idx = custom_hash(k);
                ull value = table[idx].get(k);
                cout << value << "\n";  
            }
        }
    }
    return 0;
}
