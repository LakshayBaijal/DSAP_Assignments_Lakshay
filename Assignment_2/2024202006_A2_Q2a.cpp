#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool exists_in_vector(const vector<string>& storage, const string& s) 
{
    for (const auto& str : storage) 
    {
        if (str == s) 
        {
            return true;  
        }
    }
    return false; 
}

int main() {
    int t;
    cin >> t; 

    while (t--) 
    {
        int n;
        cin >> n; 

        vector<string> encountered_strings;  

        while (n--) {
            string s;
            cin >> s;  

            if (exists_in_vector(encountered_strings, s)) 
            {
                cout << "1" << endl;  
            } 
            else 
            {
                cout << "0" << endl;
                encountered_strings.push_back(s);  
            }
        }
    }

    return 0;
}
