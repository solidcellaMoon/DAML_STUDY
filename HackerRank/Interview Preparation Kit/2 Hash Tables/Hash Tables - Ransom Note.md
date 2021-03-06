# Hash Tables: Ransom Note

**[[링크]](https://www.hackerrank.com/challenges/ctci-ransom-note/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps)**



## 내 풀이



논리가 같아도, zip이나 람다식 등등으로 for문을 한 줄로 쓰거나 `list.count()`를 쓰면 시간초과로 탈락함.

그럼 굳이 파이썬이 아니어도 괜찮지 않을까...? 특이한건 쓰지 말자 ㅠㅠ



``` python
def checkMagazine(magaz, note):
    #note, magaz = note.split(' '), magaz.split(' ') #IDE 테스트용
    dics = {}
    
    for i in note: #노트의 {단어: 출현횟수}로 딕셔너리 생성
        if i not in dics.keys(): dics[i] = 1
        else: dics[i] += 1
    
    cnt = len(dics) #딕셔너리의 단어 개수
    
    for item in magaz: #매거진에서
        if item not in dics.keys(): continue #단어가 딕셔너리에 없으면 skip
        else:
            dics[item] -= 1 #단어가 있으면 사용했으므로 딕셔너리에서 하나 뺌
            if dics[item] == 0: cnt -= 1 #dics의 값이 0이면 조건 충족임
            if cnt == 0: #note의 모든 내용을 완성했음
                print('Yes')
                return
                
    print('No')
```



## 다른 사람의 풀이

풀이 링크: [[링크]](https://somjang.tistory.com/entry/HackerRank-Hash-Tables-Ransom-Note-Python)

나랑 반대로, 딕셔너리를  `note`가 아니라 `magazine` 기준으로 만들었음.

이 쪽이 더 깔끔해보인다...

``` python
def checkMagazine(magaz, note):
    #note, magaz = note.split(' '), magaz.split(' ') #IDE 테스트용
    dics = {}
    
    for i in magaz: #잡지의 단어로 딕셔너리 생성
        if i not in dics.keys(): dics[i] = 1
        else: dics[i] += 1
    
    for item in note: #노트의 단어에서
        if item not in dics.keys(): #잡지에 해당 단어가 없으면 탈락
            print('No')
            return
        else:
            dics[item] -= 1 #단어가 있으면 사용했으므로 -1
            if dics[item] < 0: #0보다 작아지면, 잡지에 단어수가 부족하므로 탈락
                print('No')
                return
            
    print('Yes') #해당되는게 없으면 가능한 경우임.
```

