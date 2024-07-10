MOD = int(1e9 + 7)

with open("EXPTAL.INP", "r") as fin:
    a, b, c, d = map(int, fin.readline().split())
    n, m, p, q = map(int, fin.readline().split())

res = pow(a, n, MOD) + pow(b, m, MOD) + pow(c, p, MOD) + pow(d, q, MOD)
res %= MOD

with open("EXPTAL.OUT", "w") as fout:
    fout.write(str(res))
