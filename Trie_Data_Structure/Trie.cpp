#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
    TrieNode* children[26];
    bool EndOfWord;

    TrieNode()
    {
        EndOfWord = false;  

        for(int i=0; i<26; i++)
        {
            children[i] = nullptr; 
        }
    }
};

class Trie
{
    private:

    TrieNode* root;

    void autocompletefinder(TrieNode* node, string prefix, string results[], int& count)
    {
        if( node -> EndOfWord)
        {
            if(count < 100)
            {
                results[count] = prefix;
                count++;
            }
            else
            {
                return;
            }
        }

        for(int i=0;i<26;i++)
        {
            if(node -> children[i])
            {
                char currentchar = 'a' + i;
                autocompletefinder(node->children[i],prefix + currentchar, results, count);
            }
        }
    }

    bool Duplicate(string results[], int count, string word) 
    {
        for (int i = 0; i < count; i++) {
            if (results[i] == word) {
                return true;
            }
        }
        return false;
    }

    void countautocorrect(TrieNode* node,const string& word, string currentword, int index, int distance, string results[] , int& count)
    {
        if(distance > 3)
        {
            return;
        }

        if(index == word.length())
        {
            if(node -> EndOfWord && distance <= 3 &&! Duplicate(results, count, currentword))
            {
                if(count < 100)
                {
                    results[count] = currentword;
                    count++;
                }
            }
            return;
        }
    
    //Looping each character in children alphabets and recurring count for distance with storing all letter one time per recurrsion 
    for(int i=0; i < 26;i++)
    {
        if(node -> children[i])
        {
            char currentletter = 'a' + i;
            int currentdistance = distance + (currentletter != word[index]);
            countautocorrect(node -> children[i], word, currentword + currentletter, index + 1, currentdistance, results, count);
        }
    }
    //Skipping a letter in a word, Deletion of one distance but still continue
            countautocorrect(node, word, currentword, index + 1, distance + 1, results, count);
            
    //Insertion a node but skips increase in index
    for (int i = 0; i < 26; i++) 
        {
            
            if (node->children[i]) 
            {
                char currentletter = 'a' + i;
                countautocorrect(node->children[i], word, currentword + currentletter, index, distance + 1, results, count);
            }
        }

    }



    public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode* node = root;
        for (char letter : word)
        {
            int index = letter - 'a'; //Index from 0 to 25
 
            if(!node -> children[index])
            {
                node -> children[index] = new TrieNode();  //Creating new node for every letter in word
            }
            node = node -> children[index];
        }
        node -> EndOfWord = true;   //Node should link end of letter to true
    }

    bool spellcheck(string word)
    {   
        TrieNode* node = root;
        for(char letter : word)
        {
            int index = letter - 'a';

            if(!node -> children[index])
            {
                return false;     //Not in trie if any letter misses in between
            } 
            node = node -> children[index];
        }
        return node -> EndOfWord;   //Word is valid only if it reaches last letter
    }

    void autocomplete(string prefix,string results[],int &count)
    {
        TrieNode* node = root;
        count = 0;

        for(char letter : prefix)
        {
            int index = letter - 'a';
            if(!node -> children[index])
            {
                return;
            }
            node = node -> children[index];
        }


        autocompletefinder(node,prefix,results,count);
    }


    void autocorrect(string word, string results[], int& count)
    {
        count = 0;
        countautocorrect(root,word,"",0, 0, results,count);
    }
};






int main() {
    Trie trie;

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) 
    {
        string word;
        cin >> word;
        trie.insert(word);
    }
    cout<<endl;
    int querynumber[100];
    string query[100];
    for (int i = 0; i < q; i++) 
    {

        cin >> querynumber[i] >> query[i];
    }
    for(int i=0; i < q; i++)
    {

        if (querynumber[i] == 1) //Spell Check
        {
            if (trie.spellcheck(query[i])) 
            {
                cout  << "1"<< endl;
            } 
            else 
            {
                cout  << "0"<<endl;
            }
        } 
        else if (querynumber[i] == 2) //Autocomplete
        {
            string results[100];
            int count = 0;
            trie.autocomplete(query[i], results, count);
            cout << count << endl;
            for (int j = 0; j < count; j++) 
            {
                cout << results[j] << endl;
            }
        } 
        else if (querynumber[i] == 3) // Autocorrect
        {
            string results[100];
            int count = 0;
            trie.autocorrect(query[i], results, count);
            cout << count << endl;
            for (int j = 0; j < count; j++) 
            {
                cout << results[j] << endl;
            }
        } 
        else 
        {
            cout << "Invalid Input.\n";
        }
    }

    return 0;
}