N, K = map(int, input().split())
a = list(map(int, input().split()))

res = 0
for i in range(N):
    for j in range(i, N):
        if a[i] + a[j] * a[j] == K:
            res += 1

print(res)