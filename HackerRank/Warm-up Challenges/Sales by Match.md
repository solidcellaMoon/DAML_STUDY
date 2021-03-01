# Sales by Match

https://www.hackerrank.com/challenges/sock-merchant/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup



``` python
from collections import defaultdict

def sockMerchant(n, ar):
    dics = defaultdict(list) #종류를 저장할 딕셔너리
    answer = 0
    
    for i in ar: #딕셔너리로 종류별로 저장
        dics[i].append(i)
        
    for key in dics.keys():
        lens = len(dics[key]) #각 종류가 몇개씩 있나 확인
        if lens > 1: #한 종류의 개수가 2개 이상이면 정답에 속함
            answer += int(lens/2) #페어이기에 /2해서 저장
            #lens가 홀수여도, int형으로 바꿔 저장하기에 문제없음

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
    dics = defaultdict(list) #종류를 저장할 딕셔너리
    answer = 0
    
    for i in ar: #딕셔너리로 종류별로 저장
        dics[i].append(i)
        
    for key in dics.keys():
        lens = len(dics[key]) #각 종류가 몇개씩 있나 확인
        if lens > 1: #한 종류의 개수가 2개 이상이면 정답에 속함
            answer += int(lens/2) #페어이기에 /2해서 저장
            #lens가 홀수여도, int형으로 바꿔 저장하기에 문제없음

    return answer
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)

    fptr.write(str(result) + '\n')

    fptr.close()
```

