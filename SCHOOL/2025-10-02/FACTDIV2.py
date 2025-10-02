import math

with open("FACTDIV.INP", "r") as stdin:
    n, m = map(int, stdin.read().split())

nFactorial = math.factorial(n)
result = nFactorial // m

result %= int(1e9 + 7)

with open("FACTDIV.OUT", "w") as stdout:
    stdout.write(str(int(result)) + "\n")