def miniMaxSum (arr):
  lowest = min(arr)
  highest = max(arr)
  total = 0

  for i in arr:
    total += i

  print((total - highest), (total - lowest))


arr = [1,3,5,7,9]
miniMaxSum(arr)
