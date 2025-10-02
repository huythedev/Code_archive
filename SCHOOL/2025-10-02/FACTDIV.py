MOD = 10**9 + 7

with open("FACTDIV.INP", "r") as f:
    n, m = map(int, f.read().split())

fact_mod = 1
for i in range(1, n + 1):
    fact_mod = (fact_mod * i) % MOD

inv_m = pow(m, MOD - 2, MOD)

result = (fact_mod * inv_m) % MOD

with open("FACTDIV.OUT", "w") as f:
    f.write(str(result) + "\n")
