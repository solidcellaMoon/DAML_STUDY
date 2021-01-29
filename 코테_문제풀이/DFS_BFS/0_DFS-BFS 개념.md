## DFS (Depth-First-Search)
https://deepinsight.tistory.com/146

그래프에서 깊은 부분을 우선적으로 탐색합니다.

### 동작 과정
* Stack을 사용합니다
* 탐색의 시작노드를 스택에 삽입하고 방문 처리
* 스택의 최상단 노드에 방문하지 않은 인접노드가 하나라도 있다면, 그 노드를 스택에 넣고 방문 처리
* 방문하지 않은 인접 노드가 없으면, 스택에서 최상단 노드를 꺼낸다
* 더이상 2번의 과정을 수행할 수 없을 때까지 반복한다


```python
#각 노드가 연결된 정보 (2차원 리스트)
graph = [
    [],
    [2,3,8],
    [1,7],
    [1,4,5],
    [3,5],
    [3,4],
    [7],
    [2,6,8],
    [1,7]
]

#각 노드가 방문된 정보를 표현 (1차원 리스트)
visited = [False] * len(graph)
```


```python
def dfs(graph, v, visited):
    visited[v]= True
    print(v, end=' ')
    
    for i in graph[v]:
        if not visited[i]: #방문한 적 없는 노드라면
            dfs(graph, i, visited) #방문한다 - 재귀
```


```python
dfs(graph, 1, visited)
```

    1 2 7 6 8 3 4 5 

## BFS (Breadth-First-Search)

그래프에서 가까운 노드부터 우선적으로 탐색합니다.

### 동작 과정
* Queue를 사용합니다
* 탐색 시작 노드를 큐에 삽입하고 방문 처리
* 큐에서 노드를 꺼낸다
* 해당 노드의 인접 노드 중에서 방문하지 않은 노드를 모두 큐에 삽입하고 방문 처리
* 더 이상 위 과정(3~4)을 수행할 수 없을 떄까지 반복


```python
#각 노드가 연결된 정보 (2차원 리스트)
graph = [
    [],
    [2,3,8],
    [1,7],
    [1,4,5],
    [3,5],
    [3,4],
    [7],
    [2,6,8],
    [1,7]
]

#각 노드가 방문된 정보를 표현 (1차원 리스트)
visited = [False] * len(graph)
```


```python
from collections import deque

def bfs(graph, start, visited):
    
    #시작노드를 큐에 추가하고, 방문처리
    queue = deque([start])
    visited[start] = True
    
    #큐가 빌 때까지 반복한다
    while queue:
        #시작노드를 큐에서 제거한다
        v = queue.popleft()
        print(v, end=' ')
        
        #인접노드가 있다면 큐에 추가한다
        for i in graph[v]:
            if not visited[i]: #방문한 적 없는 노드를 추가
                queue.append(i)
                visited[i] = True
```


```python
bfs(graph, 1, visited)
```

    1 2 3 8 7 4 5 6 


```python

```


```python

```


```python

```


```python

```
