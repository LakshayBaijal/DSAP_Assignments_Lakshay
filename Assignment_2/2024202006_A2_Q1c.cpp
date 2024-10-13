#include <iostream>
#include <vector>
#include <string>

using namespace std;

int find_in_vector(const vector<string>& storage, const string& s) 
{
    for (size_t i = 0; i < storage.size(); i++) 
    {
        if (storage[i] == s) 
        {
            return i;  
        }
    }
    return -1;  
}

int main() {
    int t;
    cin >> t;  

    while (t--) 
    {
        int n;
        cin >> n;  

        vector<string> storage; 

        while (n--) 
        {
            int type;
            string s;
            cin >> type >> s;  

            if (type == 0) 
            {  
                int index = find_in_vector(storage, s);
                if (index != -1) 
                {
                    cout << "1" << endl;  
                } 
                else 
                {
                    storage.push_back(s); 
                    cout << "0" << endl;   
                }
            } 
            else if (type == 1) 
            {  
                int index = find_in_vector(storage, s);
                if (index != -1) 
                {
                    cout << "1" << endl; 
                } 
                else 
                {
                    cout << "0" << endl;  
                }
            } 
            else if (type == 2) 
            {
                int index = find_in_vector(storage, s);
                if (index != -1) 
                {
                    storage.erase(storage.begin() + index);  
                    cout << "1" << endl;  
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
