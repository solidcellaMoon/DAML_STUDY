# Compare the Triplets

**[[링크]](https://www.hackerrank.com/challenges/compare-the-triplets/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign)**

``` python
def compareTriplets(a, b):
    scoreA, scoreB = 0, 0;    
    
    for i in range(len(a)):
        if a[i] > b[i]: scoreA += 1
        elif a[i] != b[i]: scoreB += 1
        
    return [scoreA, scoreB]
```

