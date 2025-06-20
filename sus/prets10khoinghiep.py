a, b, c = map(int, input().split())
MOD = 1000000007

x = b ** c

ans = pow(a, x, MOD)

print(ans)
