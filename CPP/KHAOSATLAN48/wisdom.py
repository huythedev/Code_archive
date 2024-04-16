def solve(k, n):
    res = 1
    for i in range(2, n+1):
        tmp = i
        for j in range(k):
            tmp = pow(tmp, 2, 10)  
        res = (res + tmp) % 10
    return res

k, n = map(int, input().split())

print(solve(k, n))