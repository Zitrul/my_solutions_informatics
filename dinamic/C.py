n, m = map(int, input().split())
l = []
for i in range(n):
    l.append([0]*m)
l[0][0] = 1
for y in range(n):
    for x in range(m):
        #print(x, y)
        if x - 1 >= 0 and y >= 2:
            l[y][x] += l[y - 2][x - 1]
        if y - 1 >= 0 and x >= 2:
            l[y][x] += l[y - 1][x - 2]

print(l[n-1][m-1])
#print(l)