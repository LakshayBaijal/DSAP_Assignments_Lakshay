#include <iostream>
#include <vector>
#include <string>

using namespace std;

int find_key(const vector<pair<int, string>>& storage, int key) 
{
    for (size_t i = 0; i < storage.size(); i++) 
    {
        if (storage[i].first == key) 
        {
            return i;  
        }
    }
    return -1;  
}

int main() {
    int t;
    cin >> t; 

    while (t--) {
        int n;
        cin >> n;  

        vector<pair<int, string>> storage;  

        while (n--) {
            int type, key;
            string value;
            cin >> type >> key;

            if (type == 0) {  
                cin >> value;
                int index = find_key(storage, key);
                if (index != -1)
                {

                    storage[index].second = value;  
                    cout << "1" <<endl;  
                } 
                else 
                {
                    storage.push_back({key, value});  
                    cout << "0" <<endl;  
                }
            } 
            else if (type == 1) 
            {  
                int index = find_key(storage, key);
                if (index != -1) 
                {
                    cout << storage[index].second << endl;
                } 
                else 
                {
                    cout << "0" << endl;
                }
            }
        }
    }

    return 0;
}
