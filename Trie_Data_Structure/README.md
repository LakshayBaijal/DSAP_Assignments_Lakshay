##Trie-Based Autocomplete, Spellcheck, and Autocorrect System
#Overview
This project implements a Trie (prefix tree) to support:

#Spell Check: Determines whether a given word exists in the Trie.
Autocomplete: Suggests a list of words from the Trie that start with a given prefix.
Autocorrect: Provides a list of words from the Trie that are within a Levenshtein distance of 3 from the input word.
The Trie data structure is efficient for these tasks because it allows fast prefix-based lookups and word matching.

#Features
- Insert words into the Trie.
- Spell Check: Check if a word exists in the Trie.
- Autocomplete: Given a prefix, suggest words that start with that prefix.
- Autocorrect: Suggest words that are close to the input word based on Levenshtein distance.

#How It Works
Trie Insertion:

Words are inserted into the Trie, where each letter represents a node. The end of a word is marked in the Trie.
Spell Check:

The program checks if each letter of the input word exists in the Trie. If all letters are found and the end of the word is marked, the word is considered valid.
Autocomplete:

For a given prefix, the program searches the Trie for all possible words that start with that prefix and returns them.
Autocorrect:

For a given word, the program finds all words within a Levenshtein distance of 3 by exploring possible substitutions, deletions, and insertions.
Project Structure
TrieNode Class: Represents each node in the Trie.
Trie Class: Provides methods for inserting words, performing spell check, autocomplete, and autocorrect.
Main Program: Handles user input, processes the Trie operations, and displays results.

# Implementation
Create Object file by
- g++ -o Trie Trie.cpp
- ./Trie


