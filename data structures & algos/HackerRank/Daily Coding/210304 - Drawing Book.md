# Drawing Book



**[[링크]](https://www.hackerrank.com/challenges/drawing-book/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign)**



``` python
def pageCount(n, p):
    book = [i for i in range(1,n+1)] #1~n까지의 페이지 배열
    left, right = abs(p-book[0]), abs(p-book[-1]) #p부터 맨앞, 맨뒤까지의 거리
    
    #1페이지 이후 [2+2k, 3+2k]의 규칙이므로, 여기 해당하는 k를 구함 (1p부터 넘기는 기준임)
    lamTurned = lambda p: (p-2)//2 + 1 if (p%2==0) else (p-3)//2 + 1
        
    #맨앞에서 더 가까울 때
    if (left < right): return lamTurned(p)
          
    #맨뒤에서 더 가깝거나, 거리가 같을 때 -> 맨뒤의 k에서 현재 k를 빼면 역순
    else: return lamTurned(n) - lamTurned(p)
```



``` python
#!/bin/python3

import os
import sys

#
# Complete the pageCount function below.
#
def pageCount(n, p):
    
    book = [i for i in range(1,n+1)] #1~n까지의 페이지 배열
    
    left, right = abs(p-book[0]), abs(p-book[-1]) #페이지부터 맨앞, 맨뒤까지의 거리
    
    #1페이지 이후 [2+2k, 3+2k]의 규칙이므로, 여기 해당하는 k를 구함 (1p부터 넘기는 기준임)
    lamTurned = lambda p: (p-2)//2 + 1 if (p%2==0) else (p-3)//2 + 1
    k = lamTurned(p)
        
    #맨앞에서 더 가까울 때
    if (left < right): return k
          
    #맨뒤에서 더 가깝거나, 거리가 같을 때 -> 맨뒤의 k에서 현재 k를 빼면 역순
    else:
        revK = lamTurned(n) - k
        return revK

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    p = int(input())

    result = pageCount(n, p)

    fptr.write(str(result) + '\n')

    fptr.close()

```

