n, m = map(int,input().split())
d = []
import sys

sys.setrecursionlimit(10 ** 6)
used = []
for i in range(n * m):
    used.append(0)
    d.append([])
l = []
for i in range(n):
    x = input()
    l.append(x)

for i in range(n):
    for j in range(m):
        if l[i][j] == "#":
            if i < n -1:
                if l[i][j] == l[i + 1][j]:
                    d[i * m + j].append((i + 1) * m + j)
            if j < m - 1:
                if l[i][j] == l[i][j + 1]:
                    d[i * m + j].append(i * m + j + 1)
            if j > 0:
                if l[i][j] == l[i][j-1]:
                    d[i * m + j].append(i * m + j-1)
            if i > 0:
                if l[i][j] == l[i-1][j]:
                    d[i * m + j].append((i - 1) * m + j)
        else:
            used[i*m + j] =1
v = d
comp = []
#print(v)
#print(used)
def dfs(i, o):
    used[i] = 1
    comp[o].append(i)
    if i == 4:
        for elm in v[i]:
            #print("lskd;lfds;lkf;ldskf;lskf;lk;lka;lfkdsa;fasfkafadskfasd",elm, used[5])
            if used[elm] != 1:
                dfs(elm, o)
    else:
        for elm in v[i]:
            if used[elm] != 1:
                dfs(elm, o)
    return 0



kol_vo = 0
sumka = 0
while sum(used) != n*m:
    kol_vo += 1
    comp.append([])

    start = used.index(0)
    #print(start)
    dfs(start, kol_vo-1)
    #print(comp)
    #print(used)
print(kol_vo,end = "")
