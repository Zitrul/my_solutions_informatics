n = int(input())
a = []
b = []
c = []
for i in range(n):
    x,y,z = map(int,input().split())
    a.append(x)
    b.append(y)
    c.append(z)
prefix_1_group = []
prefix_3_group = []
prefix_2_group = []

for i in range(n):
    if i >=3:
        prefix_1_group.append(min(prefix_1_group[i - 1], prefix_2_group[i - 1], prefix_3_group[i - 1]) + a[i])
        prefix_2_group.append(min(prefix_1_group[i - 2], prefix_2_group[i - 2], prefix_3_group[i - 2]) + b[i - 1])
        prefix_3_group.append(min(prefix_1_group[i - 3], prefix_2_group[i - 3], prefix_3_group[i - 3]) + c[i - 2])
    if i == 0:
        prefix_1_group.append(a[i])
        prefix_2_group.append(10e10)
        prefix_3_group.append(10e10)
    if i == 1:
        prefix_1_group.append(prefix_1_group[i - 1] + a[i])
        prefix_2_group.append(b[i-1])
        prefix_3_group.append(10e10)
    if i == 2:
        prefix_1_group.append(min(prefix_1_group[i - 1], prefix_2_group[i - 1]) + a[i])
        prefix_2_group.append(prefix_1_group[i - 2] + b[i - 1])
        prefix_3_group.append(c[i-2])
k = len(prefix_1_group)
print(min(prefix_1_group[k-1], prefix_2_group[k-1],prefix_3_group[k-1]))