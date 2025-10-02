MOD = 10**9 + 7

with open("FACTDIV.INP", "r") as f:
    n, m = map(int, f.read().split())

lim = m * MOD
fact = 1

for i in range(2, n + 1):
    fact *= i
    if fact >= lim:
        fact %= lim

result = (fact // m) % MOD

with open("FACTDIV.OUT", "w") as f:
    f.write(str(result) + "\n")