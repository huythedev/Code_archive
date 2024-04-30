with open('MODM.inp', 'r') as f:
    a, b, c = map(int, f.readline().split())

res = (a * b) % c

with open('MODM.out', 'w') as f:
    f.write(str(res))