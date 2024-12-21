# Time Conversion Exercise

This exercise involves converting a time given in 12-hour AM/PM format to military (24-hour) time.

## Problem Description

### Task:
Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.

### Notes:
- `12:00:00AM` on a 12-hour clock is `00:00:00` on a 24-hour clock.
- `12:00:00PM` on a 12-hour clock is `12:00:00` on a 24-hour clock.

### Function Specification:
The function `timeConversion` takes the following parameter:
- **string `s`**: A time in 12-hour AM/PM format (e.g., `07:05:45PM`).

It returns:
- **string**: The equivalent time in 24-hour format.

### Input Format:
A single string `s` that represents a valid time in 12-hour clock format.

### Constraints:
- All input times are valid.

---

## Algorithm

1. Extract the `AM` or `PM` part from the input string.
2. Split the time into components: hours, minutes, and seconds.
3. Convert the hour based on the following rules:
   - If the time is in `PM` and the hour is not 12, add 12 to the hour.
   - If the time is in `AM` and the hour is 12, set the hour to 0.
4. Format the result into a two-digit, colon-separated string (`HH:MM:SS`).
5. Return the formatted 24-hour time.

## Key Takeaways
- **This exercise reinforces string manipulation, conditional logic, and formatting skills.
- **The solution is implemented in Python, C++, and C#, demonstrating cross-language adaptability.
- **The algorithm is efficient and runs in constant time O(1) due to fixed input size.
