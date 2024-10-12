n = int(input())
r = 1
l = [0, 0]
for i in range(2,n+1):
    #print(i , l[i-1] + 1, l[i//2] + 1 + i % 2, l[i//3]  + 1 + i % 3)
    l.append( min(l[i-1] + 1, l[i//2] + 1 + i % 2, l[i//3]  + 1 + i % 3) )
print(l[n])