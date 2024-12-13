a, b, k = map(int, input().split())

remainder = a % b

for _ in range(k):
    remainder *= 10
    digit = remainder // b
    remainder %= b

print(digit)
