arr = [-4, 3, -9, 0, 4, 1]


def plusMinus(arr):
    negatives = 0
    positives = 0
    zeros = 0
    
    for i in arr:
        if i > 0:
            positives += 1
        elif i < 0:
            negatives += 1
        else:
            zeros += 1
            
    print(f"{positives/len(arr):.6f}")
    print(f"{negatives/len(arr):.6f}")
    print(f"{zeros/len(arr):.6f}")
    
    
plusMinus(arr)
