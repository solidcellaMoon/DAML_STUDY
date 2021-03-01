# Sales by Match

https://www.hackerrank.com/challenges/sock-merchant/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup



``` python
#!/bin/python3

import math
import os
import random
import re
import sys

from collections import defaultdict

# Complete the sockMerchant function below.
def sockMerchant(n, ar):
    dics = defaultdict(list)
    answer = 0

    for i in ar:
        dics[i].append(i)
        
    for key in dics.keys():
        lens = len(dics[key])
        
        if lens > 1:
            if lens % 2 != 0:
                lens -= 1
            answer += int(lens/2)

    return answer
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)

    fptr.write(str(result) + '\n')

    fptr.close()
```

