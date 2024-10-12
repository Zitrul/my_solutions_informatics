s = int(input())
N = int(input())
A = list(map(int, input().split()))
M = int(input())
Q = list(map(int, input().split()))
for i in range(M):
    A.append(-Q[i])
K = 10001
F = [0] * (K + 1)
F[0] = 1
pref = [0] * (K + 1)
for i in range(len(A)):
    F_new = F[:]
    for k in range(1, K + 1):
        if 0 <= k - A[i] <= K and F[k - A[i]] == 1:
            F_new[k] = 1
            if pref[k] == 0:
                pref[k] = A[i]
    F = F_new
if F[s] == 1:
    while s != 0:
        if pref[s] > 0:
            print("+", pref[s], sep="", end=" ")
        else:
            print(pref[s], end=" ")
        s -= pref[s]
else:
    print("Impossible")