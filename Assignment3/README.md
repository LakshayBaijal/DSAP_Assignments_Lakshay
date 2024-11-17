# Big Integer Calculator
Problem Description
Standard data types in programming languages like C++ (int, long, long long) have limited ranges. When dealing with very large integers (e.g., numbers with hundreds or thousands of digits), these types are insufficient. The Big Integer Calculator addresses this limitation by implementing arithmetic operations (addition, subtraction, multiplication, division, exponentiation, GCD, factorial) on large integers represented as strings.

Implementation Details
Data Representation:

Big Integers: Represented as std::string to accommodate numbers of arbitrary length.
Core Operations:

Addition (add): Implements digit-by-digit addition with carry-over handling.
Subtraction (subtract): Performs digit-by-digit subtraction with borrow handling. Assumes num1 >= num2.
Multiplication (multiply): Uses the grade-school multiplication algorithm, storing intermediate results in an integer array before converting back to a string.
Division (divide): Implements integer division by repeatedly subtracting the divisor from the dividend. Returns "Undefined" if division by zero is attempted.
Exponentiation (power): Utilizes exponentiation by squaring for efficiency.
Greatest Common Divisor (gcd): Employs the Euclidean algorithm adapted for string-based big integers.
Factorial (factorial): Computes the factorial of a large number by iterative multiplication.
Helper Functions:

removeLeadingZeros: Strips unnecessary leading zeros from the result to maintain correct numerical representation.
isGreaterOrEqual: Compares two big integers represented as strings to determine if the first is greater than or equal to the second.
tokenize: Parses arithmetic expressions into tokens (numbers and operators) for evaluation.
evaluateExpression: Processes the tokens to compute the final result, handling operator precedence (multiplication and division before addition and subtraction).
Main Functionality:

Reads the number of test cases.
For each test case, reads the operation type and relevant inputs.
Executes the corresponding operation and outputs the result.

# Generic Skip List Implementation
Problem Description
A Skip List is a probabilistic data structure that allows efficient search, insertion, and deletion operations within an ordered sequence of elements. It achieves average-case time complexities similar to balanced trees but is simpler to implement. This implementation is generic, supporting various data types through C++ templates, and includes operations such as:

Insertion (insert): Adds an element to the skip list.
Removal (erase): Removes all occurrences of an element from the skip list.
Search (search): Checks if an element exists in the skip list.
Count Occurrences (countOccurrences): Counts the number of times an element appears.
Lower Bound (lowerBound): Finds the first element not less than a given value.
Upper Bound (upperBound): Finds the first element greater than a given value.
Closest Element (closestElement): Finds the element closest to a given value (applicable to numeric types).
Implementation Details
Data Structures:

SkipNode:
Represents a node in the skip list.
Contains the key (T key), a count of occurrences (int count), and an array of forward pointers (SkipNode<T> **next).
Constructor initializes the node with a specified level and key.
SkipList:
Manages the skip list operations.
Contains parameters like maxHeight, probability, and currentHeight.
Maintains a head node that acts as the starting point of the skip list.
Core Components:

Random Level Generator (randomLevel):
Determines the level of a new node based on a probability factor.
Higher levels are less likely, maintaining the skip list's probabilistic balancing.
Insertion (insert):
Navigates through the skip list to find the correct position for insertion.
Handles duplicates by incrementing the count if the key already exists.
Updates forward pointers appropriately based on the randomly assigned level.
Removal (erase):
Locates the node(s) with the specified key.
Adjusts forward pointers to exclude the removed node(s).
Decrements the current height of the skip list if necessary.
Search (search):
Traverses the skip list to determine if a key exists.
Count Occurrences (countOccurrences):
Returns the count of a specific key in the skip list.
Lower Bound (lowerBound):
Finds the first element not less than the given key.
Upper Bound (upperBound):
Finds the first element greater than the given key.
Closest Element (closestElement):
Finds the element closest to the given key, favoring the smaller one in case of ties.
Applicable only to numeric types due to the use of subtraction and absolute difference.
Templates and Comparators:

The implementation uses C++ templates to allow for generic data types.
A comparator (Comparator) is used to define the ordering of elements. By default, it uses std::less<T>.
For custom classes, a specialized comparator must be provided.
Memory Management:

Dynamic memory allocation is used for forward pointers in nodes.
Destructors ensure that all allocated memory is properly freed to prevent memory leaks.
Operations Output:

The main function processes a series of operations based on user input and outputs results only for specific commands:
Search (3): Outputs 1 if found, 0 otherwise.
Count Occurrences (4): Outputs the count.
Lower Bound (5): Outputs the lower bound value.
Upper Bound (6): Outputs the upper bound value.
Closest Element (7): Outputs the closest element.
