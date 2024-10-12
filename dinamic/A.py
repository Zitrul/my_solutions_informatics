n = int(input())
l1 = 1
l2 = 1
for i in range(n):
    l1, l2 = l2, ( l1 + l2 ) % 10
print(l1)