# 프로그래머스 힙 문제
https://programmers.co.kr/learn/courses/30/parts/12117

# 더 맵게
https://programmers.co.kr/learn/courses/30/lessons/42626

## 문제 설명
매운 것을 좋아하는 Leo는 모든 음식의 스코빌 지수를 K 이상으로 만들고 싶습니다. 모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 Leo는 스코빌 지수가 가장 낮은 두 개의 음식을 아래와 같이 특별한 방법으로 섞어 새로운 음식을 만듭니다.

#### 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)

Leo는 모든 음식의 스코빌 지수가 K 이상이 될 때까지 반복하여 섞습니다.

Leo가 가진 음식의 스코빌 지수를 담은 배열 scoville과 원하는 스코빌 지수 K가 주어질 때, 모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 섞어야 하는 최소 횟수를 return 하도록 solution 함수를 작성해주세요.


### 제한 조건
* scoville의 길이는 2 이상 1,000,000 이하입니다.
* K는 0 이상 1,000,000,000 이하입니다.
* scoville의 원소는 각각 0 이상 1,000,000 이하입니다.
* 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우에는 -1을 return 합니다.


```python
scoville = [1, 2, 3, 9, 10, 12]
K = 7
#결과 2
```

[1, 2, 3, 9, 10, 12]

-

[1,2] => 1 + (2*2) => 5

-

[3,5,9,10,12]

-

[3,5] => 3 + (5*2) => 13

-

[9,10,12,13]

-

총 두번 섞음!

----
모든 음식을 K로 만들 수 없는 경우?

최종 한개 남았는데 K보다 작으면 됨

## 풀이

### heapq
push/pop 할 때마다 자동 정렬해줌.

https://itholic.github.io/kata-more-spicy/


```python
import heapq

def solution(scoville, k):
    
    answer = 0
    scov = []
    
    for num in scoville:
        heapq.heappush(scov,num)
        
    
    while scov[0] < k:
        
        first, second = heapq.heappop(scov), heapq.heappop(scov)
        
        heapq.heappush(scov, first + (second*2))
        
        if len(scov) == 1 and scov[0] < k:
            return -1
        
        #동일한 기능
        ''' try:
            heapq.heappush(scov, heapq.heappop(scov) + (heapq.heappop(scov)*2))
            
        except IndexError:
            return -1 '''
        
        answer += 1

        
    return answer 
```


```python
solution(scoville, K)
```




    2



### 내 풀이 (실패)


```python
scoville = [1, 2, 3, 9, 10, 12]
K = 7
#결과 2

def solution(scoville, K):
    answer = 0
    is_K = False
    scov = sorted(scoville)
    
    if K == 0:
        return 0
    
    while len(scov) > 1 and not is_K:
        
        #가장 작은거, 두번째로 작은거
        first, second = scov.pop(0), scov.pop(0)
        
        new = first + (second*2)
        
        scov.append(new)
        answer += 1
        
        #정렬
        scov.sort()
        
        if scov[0] >= K:
            is_K = True
            break
        
        
    if len(scov) == 1:
        return -1
    
    return answer
```


```python
solution(scoville, K)
```




    2




```python

```


```python

```


```python

```
