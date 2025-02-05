s = 0
n,m = map(int,input().split())
used = []
v = []
for i in range(n):
    used.append(0)
    v.append([])
for i in range(m):
    a,b = map(int,input().split())
    v[a-1].append(b-1)
    v[b-1].append(a-1)
#print(v)
flag= 0
def dfs(i, last):
    global flag
    used[i] = 1
    for j in v[i]:
        if used[j] == 1 and j != last:
            flag =1
        if used[j] != 1:
            dfs(j, i)

        #else:
        #    flag = 1
    return 0
dfs(0, 0)
if sum(used) == n and flag == 0:
    print("YES")
else:
    print("NO")
#print(sum(used))
