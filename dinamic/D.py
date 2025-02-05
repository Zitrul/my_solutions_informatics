s = 0
n,m = map(int,input().split())
used = []
used_colors = []
v = []
for i in range(n):
    used.append(0)
    used_colors.append(0)
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
    if used_colors[last] == 1:
        used_colors[i] = 2
    else:
        used_colors[i] = 1

    for j in v[i]:
        if used_colors[i] == used_colors[j]:
            flag = 1
        if used[j] != 1:
            dfs(j, i)

        #else:
        #    flag = 1
    return 0

while sum(used) != n:
    start = used.index(0)
    used_colors[start] = 1
    dfs(start, start)

if flag == 0:
    print("YES")
    for i in range(len(used_colors)):
        if used_colors[i] == 1:
            print(i+1,end = " ")
else:
    print("NO")
