# Counting Valleys



화려하게 풀려하지 말고 문제를 찬찬히 코드로 옮기는게 가능한지 보자...

https://www.hackerrank.com/challenges/counting-valleys/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup



``` python
def countingValleys(steps, path):
    depth, result = 0, 0
	
    for i in range(steps): #path의 처음부터 끝까지 확인
        
        # D면 깊이를 한칸 아래로, U면 깊이를 한칸 위로
        if path[i] == 'D': depth -= 1
        else: depth += 1
            
        #깊이가 0이면 평면이고, 산이나 계곡이 끝남.
        if depth == 0 and path[i] == 'U':
            result += 1 #계곡은 U로 끝나기에, 해당하면 계곡개수++
            
    return result
```





``` python
#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'countingValleys' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER steps
#  2. STRING path
#

def countingValleys(steps, path):
    depth = 0
    result = 0

    for i in range(steps):
        
        # U: UP & D: Down
        if path[i] == 'D':
            depth -= 1
        else:
            depth += 1
            
        #sea level & valley
        if depth == 0 and path[i] == 'U':
            result += 1
            
    return result


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    steps = int(input().strip())

    path = input()

    result = countingValleys(steps, path)

    fptr.write(str(result) + '\n')

    fptr.close()
```

