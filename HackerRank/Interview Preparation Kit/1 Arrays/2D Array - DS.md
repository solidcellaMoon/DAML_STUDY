# 2D Array - DS

**[[링크]](https://www.hackerrank.com/challenges/2d-array/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays)**



**문제 조건**

* `-9` <= arr [i] [j] <= 9



따라서 가능한 최솟값은 0이 아니라, `-9 x N` 임.

조건 잘 따지자....



``` python
def hourglassSum(arr):
    n = len(arr[0]) #NxN 배열의 한 줄 길이
    maxSum = -9*(7) #max는 문제 조건에 맞춘 최솟값으로 설정
    
    for i in range(n-2):
        for j in range(n-2):
            #모양에 맞춰 슬라이스해서 더함
            sums = sum(arr[i][j:j+3]) + arr[i+1][j+1] + sum(arr[i+2][j:j+3])
            if sums > maxSum: maxSum = sums #합이 현재 max값보다 크면 갱신
            
    return maxSum
```



``` python
#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the hourglassSum function below.
def hourglassSum(arr):
    n = len(arr[0])
    maxSum = -9*(7)
    
    for i in range(n-2):
        for j in range(n-2):
            sums = sum(arr[i][j:j+3]) + arr[i+1][j+1] + sum(arr[i+2][j:j+3])
            if sums > maxSum:
                maxSum = sums
            
    return maxSum
        
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    fptr.write(str(result) + '\n')

    fptr.close()

```

