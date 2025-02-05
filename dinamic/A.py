s = 0
n,s = map(int,input().split())
used = []
v = []
for i in range(n):
    used.append(0)
    v.append([])
    l = list(map(int,input().split()))
    for j in range(n):
        if l[j]:
            #print(l, j , l[j])
            v[i].append(j)
#print(v)
def dfs(i):
    used[i] = 1
    for j in v[i]:
        if used[j] != 1:
            dfs(j)
    return 0
dfs(s-1)
print(sum(used))
