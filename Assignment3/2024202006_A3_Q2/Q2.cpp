#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>

using namespace std;

template <typename T>
class SkipNode {
public:
    T key;
    int count;          
    SkipNode<T> **next;  

    SkipNode(int level, const T& key) : key(key), count(1) {
        next = new SkipNode<T>*[level + 1];
        memset(next, 0, sizeof(SkipNode<T>*) * (level + 1));
    }

    ~SkipNode() {
        delete[] next;
    }
};

// Skip List class
template <typename T, typename Comparator = std::less<T>>
class SkipList {
private:
    int maxHeight;      
    float probability;     
    int currentHeight;      
    SkipNode<T>* head;       
    Comparator compare;    

    int randomLevel();
public:
    SkipList(int maxHeight = 16, float probability = 0.5);
    ~SkipList();

    void insert(const T& key);
    void erase(const T& key);
    bool search(const T& key);
    int countOccurrences(const T& key);
    T lowerBound(const T& key);
    T upperBound(const T& key);
    T closestElement(const T& key); 
};

template <typename T, typename Comparator>
SkipList<T, Comparator>::SkipList(int maxHeight, float probability)
    : maxHeight(maxHeight), probability(probability), currentHeight(0), compare(Comparator()) {
    head = new SkipNode<T>(maxHeight, T());
    srand(static_cast<unsigned>(time(nullptr))); 
}

template <typename T, typename Comparator>
SkipList<T, Comparator>::~SkipList() {
    SkipNode<T>* current = head->next[0];
    while (current != nullptr) {
        SkipNode<T>* temp = current;
        current = current->next[0];
        delete temp;
    }
    delete head;
}

template <typename T, typename Comparator>
int SkipList<T, Comparator>::randomLevel() {
    int level = 0;
    while (((float)rand() / RAND_MAX) < probability && level < maxHeight) {
        level++;
    }
    return level;
}

template <typename T, typename Comparator>
void SkipList<T, Comparator>::insert(const T& key) {
    SkipNode<T>* current = head;
    SkipNode<T>* update[maxHeight + 1];
    memset(update, 0, sizeof(SkipNode<T>*) * (maxHeight + 1));

    for (int i = currentHeight; i >= 0; i--) {
        while (current->next[i] != nullptr && compare(current->next[i]->key, key)) {
            current = current->next[i];
        }
        update[i] = current;
    }

    current = current->next[0];

    if (current != nullptr && !compare(key, current->key) && !compare(current->key, key)) {
        current->count++;
    } else {
        int level = randomLevel();
        if (level > currentHeight) {
            for (int i = currentHeight + 1; i <= level; i++) {
                update[i] = head;
            }
            currentHeight = level;
        }

        SkipNode<T>* newNode = new SkipNode<T>(level, key);
        for (int i = 0; i <= level; i++) {
            newNode->next[i] = update[i]->next[i];
            update[i]->next[i] = newNode;
        }
    }

}

template <typename T, typename Comparator>
void SkipList<T, Comparator>::erase(const T& key) {
    SkipNode<T>* current = head;
    SkipNode<T>* update[maxHeight + 1];
    memset(update, 0, sizeof(SkipNode<T>*) * (maxHeight + 1));

    for (int i = currentHeight; i >= 0; i--) {
        while (current->next[i] != nullptr && compare(current->next[i]->key, key)) {
            current = current->next[i];
        }
        update[i] = current;
    }

    current = current->next[0];

    if (current != nullptr && !compare(key, current->key) && !compare(current->key, key)) {
        for (int i = 0; i <= currentHeight; i++) {
            if (update[i]->next[i] != current)
                break;
            update[i]->next[i] = current->next[i];
        }
        delete current;

        while (currentHeight > 0 && head->next[currentHeight] == nullptr) {
            currentHeight--;
        }
    }


}

template <typename T, typename Comparator>
bool SkipList<T, Comparator>::search(const T& key) {
    SkipNode<T>* current = head;

    for (int i = currentHeight; i >= 0; i--) {
        while (current->next[i] != nullptr && compare(current->next[i]->key, key)) {
            current = current->next[i];
        }
    }

    current = current->next[0];

    if (current != nullptr && !compare(key, current->key) && !compare(current->key, key)) {
        return true;
    } else {
        return false;
    }
}

template <typename T, typename Comparator>
int SkipList<T, Comparator>::countOccurrences(const T& key) {
    SkipNode<T>* current = head;

    for (int i = currentHeight; i >= 0; i--) {
        while (current->next[i] != nullptr && compare(current->next[i]->key, key)) {
            current = current->next[i];
        }
    }

    current = current->next[0];

    if (current != nullptr && !compare(key, current->key) && !compare(current->key, key)) {
        return current->count;
    } else {
        return 0;
    }
}

template <typename T, typename Comparator>
T SkipList<T, Comparator>::lowerBound(const T& key) {
    SkipNode<T>* current = head;

    for (int i = currentHeight; i >= 0; i--) {
        while (current->next[i] != nullptr && compare(current->next[i]->key, key)) {
            current = current->next[i];
        }
    }

    current = current->next[0];

    if (current != nullptr) {
        return current->key;
    } else {
        return T();  
    }
}

template <typename T, typename Comparator>
T SkipList<T, Comparator>::upperBound(const T& key) {
    SkipNode<T>* current = head;

    for (int i = currentHeight; i >= 0; i--) {
        while (current->next[i] != nullptr && !compare(key, current->next[i]->key)) {
            current = current->next[i];
        }
    }

    current = current->next[0];

    if (current != nullptr) {
        return current->key;
    } else {
        return T();  
    }
}

template <typename T, typename Comparator>
T SkipList<T, Comparator>::closestElement(const T& key) {
    SkipNode<T>* current = head;
    SkipNode<T>* prev = nullptr;

    for (int i = currentHeight; i >= 0; i--) {
        while (current->next[i] != nullptr && compare(current->next[i]->key, key)) {
            current = current->next[i];
        }
    }

    prev = current;
    current = current->next[0];

    if (prev == head) {
        if (current != nullptr) {
            return current->key;
        } else {
            return T(); 
        }
    } else {
        if (current != nullptr) {
            T diffPrev = abs(prev->key - key);
            T diffCurr = abs(current->key - key);

            if (diffPrev <= diffCurr) {
                return prev->key;
            } else {
                return current->key;
            }
        } else {
            return prev->key;
        }
    }
}

int main() {
    SkipList<int> skiplist;
    int choice;
    int N;
    cin >> N;
    while (N > 0) {
        N--;
        cin >> choice;
        if (choice == 1) {
            int value;
            cin >> value;
            skiplist.insert(value);
        } else if (choice == 2) {
            int value;
            cin >> value;
            skiplist.erase(value);
        } else if (choice == 3) {
            int value;
            cin >> value;
            cout << (skiplist.search(value) ? 1 : 0) << endl;
        } else if (choice == 4) {
            int value;
            cin >> value;
            cout << skiplist.countOccurrences(value) << endl;
        } else if (choice == 5) {
            int value;
            cin >> value;
            int lb = skiplist.lowerBound(value);
            cout << lb << endl;
        } else if (choice == 6) {
            int value;
            cin >> value;
            int ub = skiplist.upperBound(value);
            cout << ub << endl;
        } else if (choice == 7) {
            int value;
            cin >> value;
            int ce = skiplist.closestElement(value);
            cout << ce << endl;
        } else
            break;
    }
    return 0;
}
