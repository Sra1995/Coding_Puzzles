#!/bin/python3

import sys

def sum_of_natural_numbers(end: int, step: int) -> int:
    count = (end -1) // step
    return count * (count + 1) * step // 2
    
def solution_closed_form(n: int) -> int:
    return (sum_of_natural_numbers(n, 3) + sum_of_natural_numbers(n, 5) - sum_of_natural_numbers(n, 15))


t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print(solution_closed_form(n))

