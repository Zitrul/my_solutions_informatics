n = int(input())

A = 1
B = 1
C = 1

for i in range(n-1):
    A, B, C = B + C, C + A + B, A + B + C
print(A + B + C)