# Minimum Swaps 2

**[[링크]](https://www.hackerrank.com/challenges/minimum-swaps-2/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays)**



## 풀이



`!=` 대신 `is not`으로 표현하면 탈락한다. 웬만하면 파이썬 고유 문법은 쓰지 말라는건지...

똑같은 코드라도 `is not` 등으로 쓰면 엄청 많이 틀리게 뜨니 주의.



풀이 참고: [[링크]](https://somjang.tistory.com/entry/HackerRank-Array-Minimum-Swaps-2-Python)



``` python
def minimumSwaps(arr):
    cnt = 0
    
    for i in range(len(arr)):
        while arr[i] != i+1:
            notsort = arr[i]
            arr[i], arr[notsort - 1] = arr[notsort - 1], notsort
            cnt += 1
            
    return cnt
```



현재 인덱스에 위치한 값이 정렬된 값(idx+1)이 될 때까지, arr[notsort-1]의 값과 swap 해주면 된다.



## 다른 풀이 (BAD..?)



swap 부분 코드 자체는 거의 똑같은데, `arr != origin` 부분이 시간을 잡아먹는 것 같다.



``` python
def minimumSwaps(arr):
    idx, cnt = 0, 0
    origin = [i for i in range(1,len(arr)+1)]
    
    while arr != origin:
        
        while arr[idx] == idx+1:
            idx += 1
        
        while arr[idx] != idx+1:
            notsort, sort = arr[idx], idx+1
            arr[sort-1], arr[notsort - 1] = arr[notsort - 1], notsort
            cnt += 1         
            
    return cnt
```

