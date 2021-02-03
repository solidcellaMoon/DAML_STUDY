# 프로그래머스 해시 문제
https://programmers.co.kr/learn/courses/30/parts/12077

# 전화번호 목록 (★★)
https://programmers.co.kr/learn/courses/30/lessons/42577

## 문제 설명
전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.

전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.

* 구조대 : 119
* 박준영 : 97 674 223
* 지영석 : 11 9552 4421

전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.


### 제한 조건
* phone_book의 길이는 1 이상 1,000,000 이하입니다.
* 각 전화번호의 길이는 1 이상 20 이하입니다.

# 내 풀이 (최종)

굳이 해시나 딕셔너리같은걸 사용할 필요가 있는지 모르겠다...?

정확하지 않아도 통과 가능한 듯 하니 일단 이 문제는 보류....




```python
phone_book = ['889521222223','11', '889521','1234325','56578','43536','667']
#결과 False (어떤 경우라도 접두어가 있으면 false!!)
```


```python
def solution(pho):
    answer = True
    
    #정렬
    pho.sort()
    
    while answer:
        
        print(pho)
        
        #접두어가 있는 경우엔, pho에 값이 남아있음
        if pho: #가장 짧은 번호를 key로 뽑는다
            key = pho.pop(0)
            print(key)
        else: #접두어가 없다면 pho가 비게 되므로 while문 탈출
            break
    
        # pho 리스트에 key가 포함된 번호가 있는지 확인
        for number in pho:
            if key in number: #있다면 False로 바꾸고 for문 탈출
                answer = False
                break
            #맨 앞자리가 다르면 비교할 필요없으니 탈출
            if key[0] != number[0]:
                print(key, number)
                break
                
    
    return answer
```


```python
solution(phone_book)
```

    ['11', '1234325', '43536', '56578', '667', '889521', '889521222223']
    11
    11 43536
    ['1234325', '43536', '56578', '667', '889521', '889521222223']
    1234325
    1234325 43536
    ['43536', '56578', '667', '889521', '889521222223']
    43536
    43536 56578
    ['56578', '667', '889521', '889521222223']
    56578
    56578 667
    ['667', '889521', '889521222223']
    667
    667 889521
    ['889521', '889521222223']
    889521
    




    False



### 가장 큰 수를 만들려면?
참고: https://github.com/solidcellaMoon/studynote/blob/master/%EC%BD%94%ED%85%8C_%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B4/%EC%A0%95%EB%A0%AC/2_%EA%B0%80%EC%9E%A5%20%ED%81%B0%20%EC%88%98.md


```python
pho = ['889521222223','11', '889521','1234325','56578','43536','667']
pho.sort(key = lambda x : x*6, reverse = True)
print(pho)
```

    ['889521', '889521222223', '667', '56578', '43536', '1234325', '11']
    

## 내 풀이 (BAD)

어쩌다보니 맞췄다


#### 접두사 인정 조건 1:
119가 접두사라면, 무조건 119로 시작하는 번호가 있어야 함

#### 접두사 인정 조건 2:
가장 짧은 번호가 접두사가 될 수 있..다고 생각했는데

아닌거 같음...

11,889521, 889521**** => 889521 가 접두사


```python
phone_book = ['119', '97674223', '1195524421']
#결과 False (어떤 경우라도 접두어가 있으면 false!!)
```


```python
def solution(pho):
    answer = True
    
    key = min(pho)
    pho.remove(key)
    
    for i in pho:
        if key in i:
            answer = False
            break
    
    
    return answer
```


```python
solution(phone_book)
```




    False




```python

```


```python

```
