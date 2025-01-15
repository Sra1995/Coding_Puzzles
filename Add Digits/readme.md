# 258. Add Digits


Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

 

Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
Example 2:

Input: num = 0
Output: 0
 

Constraints:

0 <= num <= 2^31 - 1


# Method

just like how I solved the reverse integer problem.
get first digit by using % 10
then divide by 10 to chop the zero

However, the catch here is we are doing "DIGITAL ROOT" so if the result is 3 + 8 which is 11 greater than 9 aka 10 and above we have to keep repeating the process.
