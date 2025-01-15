# 171. Excel Sheet Column Number
Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28

Example 3:

Input: columnTitle = "ZY"
Output: 701

# Method

I did a lot of ascii counting by hand during my graduate studies. A start from 65 and a from 97

basically we get each character in the string then reduct 64 from it and pump it up by 26 each time we move index

like on this :
Input: columnTitle = "AB"
A = 26 * 1 + 66-64 = 26 + 2 = 28 
Output: 28


