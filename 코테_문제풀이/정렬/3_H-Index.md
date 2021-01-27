# 프로그래머스 정렬 문제
https://programmers.co.kr/learn/courses/30/parts/12198

# H-Index
https://programmers.co.kr/learn/courses/30/lessons/42747

## 문제 설명
H-Index는 과학자의 생산성과 영향력을 나타내는 지표입니다. 어느 과학자의 H-Index를 나타내는 값인 h를 구하려고 합니다. 위키백과1에 따르면, H-Index는 다음과 같이 구합니다.


어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-Index입니다.


어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때, 이 과학자의 H-Index를 return 하도록 solution 함수를 작성해주세요.


### 제한사항
* 과학자가 발표한 논문의 수는 1편 이상 1,000편 이하입니다.
* 논문별 인용 횟수는 0회 이상 10,000회 이하입니다.

풀이: https://eda-ai-lab.tistory.com/471


```python
#입출력 예
citations = [3, 0, 6, 1, 5]
# return = 3
```


```python
def solution(citations):
    #내림차순 정렬
    citations.sort(reverse=True)
    
    #enumerate로 순서 잡기
    arr = enumerate(citations, start=1)
    for i, value in arr:
        print(i,":",value)
        
    #인덱스와 비교해서 작은 수 추출
    arr = list(map(min, enumerate(citations, start=1)))
    print(arr)
    
    # 그 중 가장 큰 값
    print(max(arr))
    
    #위의 과정을 한줄로 요약
    answer = max(map(min, enumerate(citations, start=1)))
    
    return answer
```


```python
solution(citations)
```

    1 : 6
    2 : 5
    3 : 3
    4 : 1
    5 : 0
    [1, 2, 3, 1, 0]
    3
    




    3



## 배워둘 것
## range & enumerate 함수

### range 함수

#### range(start, stop, step)
* start~stop-1까지 step 단위로 증감



```python
print(list(range(5))) #[0, 1, 2, 3, 4]

print(list(range(1,6))) #[1, 2, 3, 4, 5]
print(list(range(1,6,2))) #[1, 3, 5]

print(list(range(6,1,-1))) #[6, 5, 4, 3, 2]
print(list(range(6,1,-2))) #[6, 4, 2]
```

    [0, 1, 2, 3, 4]
    [1, 2, 3, 4, 5]
    [1, 3, 5]
    [6, 5, 4, 3, 2]
    [6, 4, 2]
    

### enumerate 함수 (★)

#### enumerate(sequence, start=0)

* enumerate는 “열거하다”라는 뜻입니다.
* 리스트가 있는 경우 순서와 리스트의 값을 전달하는 기능을 가집니다.
* 이 함수는 순서가 있는 자료형(list, set, tuple, dictionary, string)을 입력으로 받아 인덱스 값을 포함하는 enumerate 객체를 리턴합니다.
* 보통 enumerate 함수는 for문과 함께 자주 사용됩니다.
* start=1로 하면 인덱스가 1부터 시작 (기본은 0부터 시작)

https://wikidocs.net/20792


```python
arr = enumerate((1,2,3))
for i, value in arr:
    print(i,":",value)

print()

arr = enumerate([1,2,3])
for i, value in arr:
    print(i,":",value)

print()

dict1 = {'이름': 'aaa', '나이': 11}
data = enumerate(dict1)
for i, key in data:
    print(i, ":", key, dict1[key])
    
print()

data = enumerate("안녕 하세요")
for i, value in data:
    print(i, ":", value)
    
print()
```

    0 : 1
    1 : 2
    2 : 3
    
    0 : 1
    1 : 2
    2 : 3
    
    0 : 이름 aaa
    1 : 나이 11
    
    0 : 안
    1 : 녕
    2 :  
    3 : 하
    4 : 세
    5 : 요
    
    


```python

```
