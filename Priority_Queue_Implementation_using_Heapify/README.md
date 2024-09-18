## Priority Queue [20 marks]
# a. [15 marks]
Problem Statement: Implement priority queue
What is a priority queue?
​ ● A priority queue is a data structure that maintains a collection of
elements,
each associated with a priority or value. Elements are stored in a way that
allows the retrieval of the element with the highest (or lowest) priority
quickly.
​ ● Unlike deques or lists, a priority queue doesn't maintain the elements in
any specific order based on their values, except for ensuring that the
highest (or lowest) priority element is readily accessible.
Operations : The C++ standard specifies that a legal (i.e.,
standard-conforming) implementation of priority queue must satisfy the
following performance requirements.
- priority_queue() - initialize an empty priority queue. Time complexity: O(1)
- int size() - returns the current size of the priority queue. Time complexity:
O(1)
- void push(int el) - insert an element el in the priority queue. Time
complexity: O(log(size()))
- int top() - returns the top (highest or lowest priority) element in the priority
queue. Time complexity: O(1)
- void pop() - remove the top element of the priority queue. Time
complexity: O(log(size()))
- bool empty() - returns true if the priority queue is empty else returns false.
Time complexity: O(1)
# b. [5 marks]
Problem Statement : David's Bakery has introduced a new promotion for
students. Under this promotion, he monitors his daily sales, and if the sales on a
specific day is greater than or equal to the combined sum of the median sale
for a trailing number of d days and the median sale from the first day of the
promotion, (follow through the example included below to understand better)
then he offers free 'Cheeeeeese Maggi' to the first five customers on the
following day. However, David will only provide this free offer if he has transaction
data for at least the trailing number of d prior days.
Given the number of trailing days d and the daily sales record for David's Bakery
over a period of n days, can you determine how many days david will offer free
maggi to students during this entire period of n days?
Input Format :
​- The first line contains two space-separated integers n and d, the number
of days of daily sales data, and the number of trailing days respectively.
​- The second line contains n space-separated non-negative integers
where each integer i denotes sales[i].
Output Format :
- int: the total number of days david will offer free maggi to students.
Constraints :
- 1<=n<=2*10^5
- 1<=d<n
- 1 <= sales[i] <= 10^5
10a. Sample input:
85
23421636
Sample output:

2

# Explanation:
For the first five days, david will not offer any free maggi to students because he
didn’t have sufficient sales data.
On the sixth day, David has d = 5 days worth of trailing sales data, which is {2, 3,
4, 2, 1}. The median sale of the preceding five days is 2, and he also has the
entire sales data from the beginning, which remains {2, 3, 4, 2, 1}, with a median
sale value of 2 as well. Since, David's sales on the 6th day is greater than the
combined sum, David offers free Maggi to students for the 6th day.
On the seventh day, David has d = 5 days worth of trailing sales data, which is {3,
4, 2, 1, 6}. The median sale of the preceding five days is 3, and he also has the
entire sales data from the beginning, which is {2, 3, 4, 2, 1, 6}, with a median sale
value of (2 + 3) / 2 = 2.5 . Since, David's sales on the 7th day is less than the
combined sum, he will not offer free Maggi to students for the 7th day.
On the eighth day, David has d = 5 days worth of trailing sales data, which is {4,
2, 1, 6, 3}. The median sale of the preceding five days is 3, and he also has the
entire sales data from the beginning, which is {2, 3, 4, 2, 1, 6, 3}, with a median
sale value of 3 as well. Since, David's sales on the 8th day is equal to the
combined sum, David offers free Maggi to students for the 8th day.
Therefore, in total david will offer free maggi for 2 days (6th and 8th day).
