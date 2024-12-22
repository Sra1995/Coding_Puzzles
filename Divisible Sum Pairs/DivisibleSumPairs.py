def divisibleSumPairs(n, k, ar):
    # Write your code here
    if n == 0:
        return 0
        
    remainder_count = [0] * k
    count = 0
    for i, num in enumerate(ar):
        remainder = num % k
        complement = (k - remainder) % k
        
        count += remainder_count[complement]
        
        
        remainder_count[remainder] += 1
            
    return count

ar = [1,3,2,6,1,2]
k = 5
n = len(ar)

print(divisibleSumPairs(n, k, ar))
