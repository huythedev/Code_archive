MOD = 998244353

def solve(a, b):
    x = max(a, b)
    y = min(a, b)
    res = (x * (x + 1) // 2 - y * (y - 1) // 2) % MOD

    while y > 0:
        x, y = max(x - y, y), min(x - y, y)
        res = (res + (x * (x + 1) // 2 - y * (y - 1) // 2)) % MOD

    return res

# Đọc input
a, b = map(int, input().split())

# Tính và in ra kết quả
result = solve(a, b)
print(result)