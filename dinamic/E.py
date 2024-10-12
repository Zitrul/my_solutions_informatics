N, M = map(int, input().split())
m = list(map(int,input().split()))
c = list(map(int,input().split()))
l = []
for i in range(N+1):
    l.append([])
    for j in range(M+1):
        l[i].append(0)
for i in range(1,N+1):
    for j in range(1,M+1):
        if j >= m[i-1]:
            l[i][j] = max(l[i-1][j-m[i-1]] + c[i-1],l[i-1][j])
        else:
            l[i][j] = l[i - 1][j]

#print(l)
print(l[N][M])