# Jumping on the Clouds



**[[링크]](https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup)**

배열에서 예외처리 하는 습관을 잘 들여야 한다...



``` python
def jumpingOnClouds(c):
    now, cnt = 0, 0
    
    while now != len(c) - 1: #끝까지 갈 때까지
        cnt += 1 #매번 1씩 카운트
        
        if now != len(c) - 2: #배열 범위 내에서 무조건 두칸씩 이동
            now += 2
            if c[now] == 1: # 두칸 갔는데 지뢰면 한칸 후퇴
                now -= 1
                
        else: #두칸째가 없으면 다 왔으므로 while 탈출
            break
    
    return cnt
```





``` python
#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the jumpingOnClouds function below.
def jumpingOnClouds(c):
    now, cnt = 0, 0
    
    while now != len(c) - 1: #끝까지 갈 때까지
        cnt += 1 #매번 1씩 카운트
        
        if now != len(c) - 2: #배열 범위 내에서 무조건 두칸씩 이동
            now += 2
            if c[now] == 1: # 두칸 갔는데 지뢰면 한칸 후퇴
                now -= 1
                
        else: #두칸째가 없으면 다 왔으므로 while 탈출
            break
    
    return cnt

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    c = list(map(int, input().rstrip().split()))

    result = jumpingOnClouds(c)

    fptr.write(str(result) + '\n')

    fptr.close()

```

