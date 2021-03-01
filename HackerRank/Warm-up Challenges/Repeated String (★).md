# Repeated String (★)



ㅠㅠㅠㅠ....

진짜 터무니없는 상황에서 돌아가는지...?

https://www.hackerrank.com/challenges/repeated-string/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup



``` python
def repeatedString(s, n):
    
    longStr = n // len(s) #n개를 만들기 위해 s를 최소 몇번 곱해야하는지?
    answer = longStr * s.count('a') #그게 k번 만큼이면, s의 a개수에도 k를 곱함
    
    if n % len(s) != 0: #아직 부족할 경우
        answer += s[:n % len(s)].count('a') #부족한 만큼의 s부분의 a개수를 더함
        
    return answer
```



``` python
#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the repeatedString function below.
def repeatedString(s, n):
    
    longStr = n // len(s)
    answer = longStr * s.count('a')
    
    if n % len(s) != 0:
        answer += s[:n % len(s)].count('a')
        
    return answer

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    n = int(input())

    result = repeatedString(s, n)

    fptr.write(str(result) + '\n')

    fptr.close()

```

