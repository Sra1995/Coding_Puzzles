# Breaking Records - Basketball Season

This problem involves keeping track of Maria's basketball scores over a season. As she plays each game, she records the number of times she breaks her personal records for the most and least points scored in a game. The task is to determine how many times she breaks these records throughout the season.

## Problem Description

Given a list of scores, each representing the number of points Maria scored in a game, determine the number of times she breaks her personal record for the highest score (`maximum`) and the lowest score (`minimum`).

The first game sets her initial record for both maximum and minimum scores, and each subsequent game is compared to these records.

### Input Format

1. The first line contains an integer `n`, the number of games.
2. The second line contains `n` space-separated integers, each representing the score for the respective game.

### Output Format

Return an array or list of two integers:
1. The number of times she breaks her record for the maximum score.
2. The number of times she breaks her record for the minimum score.

### Example

**Input:**
```
12 24 10 24
```

**Output:**
```
1 1
```

### Explanation:

- **First Game (12)**: No records are broken.
- **Second Game (24)**: Breaks the maximum record.
- **Third Game (10)**: Breaks the minimum record.
- **Fourth Game (24)**: No new records are broken.

Thus, Maria breaks her maximum record 1 time and her minimum record 1 time.

---

## Constraints
- The number of games `n` is between `1` and `1000`.
- Each score is a valid integer within the range of typical basketball scores.

This problem helps reinforce skills related to tracking records, iteration, and conditional logic, all of which are useful in various coding interviews.
```
