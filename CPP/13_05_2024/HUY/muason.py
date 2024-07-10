with open('MUASON.inp', 'r') as infile:
    N = int(infile.readline().strip())
    num = list(map(int, infile.readline().strip().split()))

res = 2 ** N - 1;

with open('MUASON.out', 'w') as outfile:
    outfile.write(str(res))
