# Array Manipulation

**[[링크]](https://www.hackerrank.com/challenges/crush/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays)**



## 풀이

풀이 링크: [[링크]](https://somjang.tistory.com/entry/HackerRank-Arrays-Array-Manipulation-Python)



``` python
def arrayManipulation(n, queries):
    
    arr = [0 for _ in range(n+1)]
    maxNum, total = 0, 0
    
    for left, right, k in queries:
        arr[left - 1] += k
        arr[right] -= k
    
    for i in range(len(arr)):
        total += arr[i]
        if maxNum < total:
            maxNum = total
    
    return maxNum
```



### 과정

**조건:**

```
10
[1,5,3]
[4,8,7]
[6,9,1]
```



#### 1. 배열 길이 설정

n+1의 길이만큼 초기화 한다.

```
[0,0,0,0,0,0,0,0,0,0]
```



#### 2. 쿼리문 삽입

* 첫번째 쿼리는 1~5 범위에 3을 더한다.

  즉, 인덱스상 arr[0~4]까지에는 3이 더해지고,

  범위를 이탈한 5부터는 아니기에, arr[5]에는 -3으로 표현한다.

* 두번째 쿼리는 4~8 범위에 7을 더한다.

  과정은 위와 같다.

* 마지막 쿼리는 6~9 범위에 1을 더한다.

  즉, 인덱스상 arr[5~8]까지 1이 더해진다.

  arr[5]는 첫쿼리의 3의 범위가 끝나는 동시에 마지막쿼리의 시작 위치이다.

```
[3, 0, 0, 0, 0, -3, 0, 0, 0, 0, 0]
[3, 0, 0, 7, 0, -3, 0, 0, -7, 0, 0]
[3, 0, 0, 7, 0, -2, 0, 0, -7, -1, 0]
```



#### 3. 최댓값 찾기

for문으로 배열 원소를 하나씩 방문하며 배열 끝까지 확인한다.

이 때 최댓값을 갱신한다.

```
arr = [3, 0, 0, 7, 0, -2, 0, 0, -7, -1, 0]

for i in range(len(arr)):
	total += arr[i]
	if maxNum < total:
		maxNum = total
```





## 다른 풀이(BAD)

문제 내용 그대로 구현하면 시간초과가 뜸.

``` python
def arrayManipulation(n, queries):
    arr = [0 for _ in range(n)] 
    for left, right, k in queries:
        for i in range(left-1,right): #이부분이 문제라고 봄
            arr[i] += k
    
    return max(arr) #여기도...
```

