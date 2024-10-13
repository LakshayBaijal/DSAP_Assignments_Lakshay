# String Processing System: Efficient Storage and Retrieval
## Overview
This project addresses multiple problems related to string processing and key-value storage. The solution aims to handle large-scale data efficiently, using optimized storage techniques. The problems have been solved while keeping the constraints in mind, such as minimizing memory usage and maintaining time efficiency.

Questions Implemented:
Q1B: Online Processing with an associative array
Q1C: Efficient storage and retrieval of strings without using unordered data structures
Q2A: Memory-efficient system for checking string existence
Problem Descriptions
Q1B: Online Processing
In this problem, the goal is to implement a system to process operations on an associative array. There are two types of operations:

Store Operation: Given a key and value, store them in the system. If the key already exists, the value is updated.
Retrieve Operation: Given a key, return the associated value or 0 if the key does not exist.
Solution Implementation:

A custom key-value store is implemented using a vector<pair<ull, ull>>, where each pair stores the key and its associated value.
A simple linear search is used to check if a key already exists before updating or inserting a new key-value pair.
Key Highlights:

Custom hash function is used to distribute keys across a hash table of size 524287 (a large prime number).
The solution implements efficient key-value lookups and updates using a hash table with chaining to handle collisions.
Q1C: Efficient String Storage without Unordered Structures
In this problem, the goal is to store and check the existence of strings using only vectors and strings, without using unordered sets or maps. The system processes queries to:

Insert a String: Add a string if it's new, or mark it as already present if it exists.
Check for Existence: Determine if a string has been previously encountered.
Solution Implementation:

The solution uses a vector<string> to store encountered strings.
For each query, the system checks if the string already exists using a linear search. If the string is found, it outputs 1; otherwise, it outputs 0 and inserts the new string.
Key Highlights:

The approach ensures no unordered data structures are used.
The solution efficiently handles string insertions and existence checks.
Q2A: Memory-Efficient String Processing System (Never Again MLE)
The problem asks for a system to efficiently check for the presence of a set of strings while minimizing memory usage. The challenge is to optimize the system for both time and space, given large amounts of input data.

Solution Implementation:

A polynomial rolling hash function is used to convert each string into a hash value.
Instead of storing the actual strings, the system stores and checks hash values in a vector<unsigned long long>.
For each new string, the system computes its hash and checks if the hash exists in the vector.
Key Highlights:

Memory-efficient solution by storing only hash values rather than the full strings.
Polynomial rolling hash ensures a good distribution of hash values to avoid collisions.
