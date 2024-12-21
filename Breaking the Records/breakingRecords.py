def breakingRecords(scores):
    minimum = scores[0]
    maximum = scores[0]
    record = [0, 0] # max_breaks, min_breaks
    
    for score in scores[1:]:
        if score > maximum:
            maximum = score
            record[0] += 1
        if score < minimum:
            minimum = score
            record[1] += 1
    return record


scores = [12,24,10,24]
print(breakingRecords(scores))
