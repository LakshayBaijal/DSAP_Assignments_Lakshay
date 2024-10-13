#include <iostream>
#include <vector>
using namespace std;

struct KeyValue {
    long long key;
    long long val;
};

void update_or_insert(vector<KeyValue>& pairs, long long key, long long value)
 {
    for (auto& pair : pairs) 
    {
        if (pair.key == key) 
        {
            pair.val = value;  
            return;
        }
    }
    pairs.push_back({key, value});
}

long long search_key(const vector<KeyValue>& pairs, long long queryKey) 
{
    for (const auto& pair : pairs) 
    {
        if (pair.key == queryKey)
         {
            return pair.val;
        }
    }
    return 0; 
}

int main() 
{
    int test_cases;
    cin >> test_cases;

    while (test_cases--) 
    {
        int num_operations;
        cin >> num_operations;

        vector<KeyValue> keyValueStore;

        for (int i = 0; i < num_operations; i++) 
        {
            long long key, value;
            cin >> key >> value;

            update_or_insert(keyValueStore, key, value);
        }

        int queries;
        cin >> queries;

        for (int i = 0; i < queries; i++)
         {
            long long queryKey;
            cin >> queryKey;

            cout << search_key(keyValueStore, queryKey) << endl;
        }
    }

    return 0;
}
