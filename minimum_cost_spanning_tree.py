import heapq

v = int(input())
graph = []
for _ in range(v):
    row = list(map(int, input().split()))
    graph.append(row)

visited = [False] * v
heap = [(0, 0)]
total = 0

while heap:
    cost, u = heapq.heappop(heap)
    if visited[u]:
        continue
    visited[u] = True
    total += cost
    for v2 in range(v):
        if not visited[v2] and graph[u][v2] != 0:
            heapq.heappush(heap, (graph[u][v2], v2))

print(total)
