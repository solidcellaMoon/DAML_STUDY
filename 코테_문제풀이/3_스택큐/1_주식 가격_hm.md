# 프로그래머스 스택/큐 문제
https://programmers.co.kr/learn/courses/30/parts/12081

# 주식 가격
https://programmers.co.kr/learn/courses/30/lessons/42584

## 문제 설명
초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때, 가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.

### 제한 조건
* prices의 각 가격은 1 이상 10,000 이하인 자연수입니다.
* prices의 길이는 2 이상 100,000 이하입니다.

풀이: https://kangmin1012.tistory.com/25


```python
prices = [1, 2, 3, 2, 3]
# 결과 = [4, 3, 1, 1, 0]
```


```python
from collections import deque

def solution(prices):
    answer = []
    
    #큐에 가격 정보를 넣음
    queue = deque(prices)
    
    while queue:
        
        #하나 꺼냄
        price = queue.popleft()
        #시간세기용
        time = 0
        
        for i in queue:
            #큐의 요소를 하나씩 돌때마다 시간 += 1
            time += 1
            
            #만약 꺼냈던 값이 지금 비교하는 값보다 크다면?
            # 가격이 떨어졌으므로 비교 멈춤
            if price > i:
                break
                
        #정답에 시간정보 추가
        answer.append(time)
        
    return answer
```


```python
solution(prices)
```




    [4, 3, 1, 1, 0]



### 내 풀이 (효율성 실패)


```python
def solution(prices):
    answer = []
    
    for idx, price in enumerate(prices):
    
        stack = []
        time = 0

        #자신 이후의 주식들을 스택에 넣음
        for i in range(idx+1, len(prices)):
            stack.append(prices[i])

        for j in stack:

            #자신보다 크거나 같다면 +=1
            if j >= price:
                time += 1      

            #그렇지 않은 경우가 오기 직전까지 값이 떨어지지 않았으므로
            #+1초한 후 루프 종료
            else: 
                time += 1
                break
                
        answer.append(time)
    
    return answer
```


```python
solution(prices)
```




    [4, 3, 1, 1, 0]




```python

```


```python

```


```python

```
