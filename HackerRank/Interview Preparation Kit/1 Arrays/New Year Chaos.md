# New Year Chaos

**[[링크]](https://www.hackerrank.com/challenges/new-year-chaos/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays)**



## 풀이

**[[링크]](https://kinchi22.github.io/2019/02/20/new-year-chaos/)**

**핵심**: 현재보다 뒤에 있는 리스트중에 현재보다 작은 값이 있다면 **뇌물 확실**

left보다 right, 즉 줄의 맨 끝부터 세는게 효율적인듯

``` python
def minimumBribes(q):
    cnt = 0
    mins = [sys.maxsize, sys.maxsize]
    
    for origin, now in reversed(list(enumerate(q,1))):
        
        if now - origin > 2:
            print('Too chaotic')
            return
        elif now > mins[1]:
            cnt += 2
        elif now > mins[0]:
            cnt += 1
            
        if now < mins[0]:
            mins = [now, mins[0]]
        elif now < mins[1]:
            mins = [mins[0], now]
            
    print(cnt)
```



## 내 풀이(BAD)

다 시간제한에서 탈락함.

그리고 `현재 뒤의 모든 수` 가 아닌, `현재의 한 칸씩 앞뒤 수`만 고려해서 풀이가 복잡했음. 

### 첫 번째

위의 풀이와 핵심은 똑같지만 sort, 슬라이싱에서 시간 오래걸림.

매번 현재 최솟값을 하나씩 비교하며 갱신하는게 나은 이유...

``` python
def minimumBribes(q):
    cnt = 0
    
    for idx, now in reversed(list(enumerate(q))):
        
        if now - (idx+1) > 2:
            print('Too chaotic')
            return
        
        back = sorted(q[idx:])[:2]
        
        for mins in back:
            if mins < now:
                cnt += 1
            else:
                break
                
    print(cnt)
```



### 두 번째

초기 상태와 현재 상태를 비교하며 pop, append로 하나씩 순서를 맞춰나감.

정렬되는 순서 자체는 맞는데... 시간복잡도는 비효율적...

```python
def minimumBribes(q):
    origin = [i for i in range(1,len(q)+1)]
    isBroken = False
    cnt = 0
    
    for idx, num in enumerate(q):
        diff = origin.index(num) - idx
        
        if(diff != 0):
            if (origin.index(num) - idx) > 2:
                print('Too chaotic')
                isBroken = True
                break
            else:
                cnt += abs(diff)
                
            target = origin.pop(origin.index(num))
            origin.insert(idx,target)      
            
        if origin == q:
            break
            
    if not isBroken:
        print(cnt)
```

