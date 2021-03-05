# Arrays - Left Rotation

**[[링크]](https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays)**



return값을 str로 바꿨는데 자꾸 안돼서 보니까 배열을 그대로 return하라는거였음...



``` python
from collections import deque

def rotLeft(a, d):
    a = deque(a)
    
    for _ in range(d):
        a.append(a.popleft())
        
    return a
```



``` python
#!/bin/python3

import math
import os
import random
import re
import sys

from collections import deque

# Complete the rotLeft function below.
def rotLeft(a, d):
    
    a = deque(a)
    
    for _ in range(d):
        a.append(a.popleft())
        
    return a
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nd = input().split()

    n = int(nd[0])

    d = int(nd[1])

    a = list(map(int, input().rstrip().split()))

    result = rotLeft(a, d)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()

```

