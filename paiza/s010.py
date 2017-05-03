# coding: utf-8
# 自分の得意な言語で
# Let's チャレンジ！！
import heapq
m, n = map(int, input().split())
mp = [input().split() for i in range(n)]
h = []
visited = [[0 for j in range(m)] for i in range(n)]
for i in range(n):
    for j in range(m):
        if mp[i][j] == 's':
            heapq.heappush(h, (0, i, j))
dist = [(1, 0), (0, 1), (-1, 0), (0, -1)]
res = 10000000000
while len(h) > 0:
    next_p = heapq.heappop(h)
    x, y = next_p[1], next_p[2]
    visited[x][y] = 1
    for d in dist:
        nx, ny = x + d[0], y + d[1]
        if nx >= 0 and nx < n and ny >= 0 and ny < m and mp[nx][ny] == '0' and visited[nx][ny] != 1:
            heapq.heappush(h, (next_p[0] + 1, nx, ny))
        elif nx >= 0 and nx < n and ny >= 0 and ny < m and mp[nx][ny] == 'g':
            res = min(res, next_p[0] + 1)
            break
if res == 10000000000:
    print("Fail")
else:
    print(res)
