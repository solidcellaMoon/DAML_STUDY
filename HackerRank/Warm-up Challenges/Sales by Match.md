# Sales by Match

https://www.hackerrank.com/challenges/sock-merchant/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup



``` python
from collections import defaultdict

def sockMerchant(n, ar):
    dics = defaultdict(list)
    answer = 0

    for i in ar: #딕셔너리로 종류별로 저장
        dics[i].append(i)
        
    for key in dics.keys():
        lens = len(dics[key]) #각 종류가 몇개씩 있나 확인
        if lens > 1: #1개 이상이면 정답에 속함
            if lens % 2 != 0: #홀수면 1개 지움
                lens -= 1
            answer += int(lens/2) #페어이기에 /2해서 저장

    return answer
```





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

