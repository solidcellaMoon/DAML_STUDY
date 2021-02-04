# 프로그래머스 해시 문제
https://programmers.co.kr/learn/courses/30/parts/12077

# 완주하지 못한 선수 (★)
https://programmers.co.kr/learn/courses/30/lessons/42576

## 문제 설명
수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.

마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.

### 제한 조건
* 마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
* completion의 길이는 participant의 길이보다 1 작습니다.
* 참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
* 참가자 중에는 동명이인이 있을 수 있습니다.

풀이: https://wooaoe.tistory.com/m/71

## 풀이 1: dictionary 사용 (★★★)

#### hash() : return the hash value of the object (if it has one)
* hash()는 각 값에 대한 고유한 정수형 숫자를 반환해준다.

* 따라서 key = 고유한 값 / value = list 값이 되어 Dictionary 형태로 담기게된다.

* participant의 hash값을 temp에 다 더해준 뒤, completetion의 hash값을 빼준다.

* 연산된 temp를 dic의 key로 불러와 answer에 담아주고 반환하면 완주하지 못한 선수가 나오게 된다. (동명이인 문제도 해결) 


참고: https://wooaoe.tistory.com/m/71


```python
participant = ['leo', 'kiki', 'eden','eden']
completion = ['eden', 'kiki','leo']
#결과: 에덴
```


```python
def solution(participant, completion):
    answer = ''
    temp = 0
    dic = {}
    
    for par in participant:
        dic[hash(par)] = par
        temp += int(hash(par))
        
    for com in completion:
        temp -= hash(com)
        
    answer = dic[temp]
    
    print(dic)
    
    return answer
```


```python
solution(participant, completion)
```

    {-4449047404052440825: 'leo', -6307346689883993739: 'kiki', 2314018515277788103: 'eden'}
    




    'eden'



### hash() 연습


```python
print(hash('a'))
print(hash('a'))
print(hash('a111'))
print(hash('b'))
```

    -427842778927709090
    -427842778927709090
    -4590790600709797406
    -1423789461349305725
    

## 풀이 2: Collections 사용

#### import collections

* collections에 내장된 함수인 Counter()는 Dic과 같이 hash형 자료들의 값의 개수를 셀 때 사용 
* Dic처럼 {key:value} 형식으로 만들어짐 
* Counter() 객체끼리 빼는 것도 가능
* 0 (zero) 나 음수 (minus)의 값들도 가능
* 해당하는 값이 없더라도 error가 아닌 0을 반환 (오..!)

참고: https://wooaoe.tistory.com/m/71


```python
participant = ['leo', 'kiki', 'eden','eden']
completion = ['eden', 'kiki','leo']
#결과: 에덴
```


```python
import collections as col

def solution(participant, completion):
    answer = ''
    par = sorted(participant)
    com = sorted(completion)
    
    result = col.Counter(par) - col.Counter(com)
    answer = list(result)[0]
    
    return answer
```


```python
solution(participant, completion)
```




    'eden'



### collections 연습


```python
import collections as col

lst = ['aa', 'cc', 'dd', 'aa', 'bb', 'ee']
dic = col.Counter(lst)
print(dic)
print()
print('list화:',list(dic))
print()
print('keys():',list(dic.keys()))
print()
print('values():',list(dic.values()))
print()
print('items():',list(dic.items()))
print()
print('counter 고유')
print('elements:',list(dic.elements()))
```

    Counter({'aa': 2, 'cc': 1, 'dd': 1, 'bb': 1, 'ee': 1})
    
    list화: ['aa', 'cc', 'dd', 'bb', 'ee']
    
    keys(): ['aa', 'cc', 'dd', 'bb', 'ee']
    
    values(): [2, 1, 1, 1, 1]
    
    items(): [('aa', 2), ('cc', 1), ('dd', 1), ('bb', 1), ('ee', 1)]
    
    counter 고유
    elements: ['aa', 'aa', 'cc', 'dd', 'bb', 'ee']
    

---

## 내 풀이 1 (BAD)

정답 자체는 쉽게 나오지만 효율성 꽝 ㅠㅠ


```python
participant = ['leo', 'kiki', 'eden','eden']
completion = ['eden', 'kiki','leo']
#결과: 에덴
```


```python
def solution(participant, completion):
    answer = ''
    par = participant
    com = completion
    
    while len(par) > 1:
        name = par.pop(0)

        if name not in com:
            par.append(name)
        else:
            com.remove(name)

    answer = par.pop()
    
    return answer
```


```python
solution(participant, completion)
```




    'eden'



## 내 풀이 2 (BAD)

try except는 써볼 수 있었음...


```python
participant = ['leo', 'kiki', 'eden','eden']
completion = ['eden', 'kiki','leo']
#결과: 에덴
```


```python
def solution(participant, completion):
    answer = ''
    par = participant
    com = completion
    
    while len(par) > 1:
        name = par.pop(0)
        
        try:
            com.remove(name)
        except:
            par.append(name)
            
    answer = par.pop()
    
    return answer
```


```python
solution(participant, completion)
```




    'eden'




```python

```


```python

```


```python

```
