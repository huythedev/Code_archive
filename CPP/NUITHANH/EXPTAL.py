MOD = int(1e9 + 7)

def main():
    with open("EXPTAL.INP", "r") as f_input:
        a, b, c, d = map(int, f_input.readline().split())
        n, m, p, q = map(int, f_input.readline().split())  

    res = pow(a, n, MOD) + pow(b, m, MOD) + pow(c, p, MOD) + pow(d, q, MOD)
    res %= MOD

    with open("EXPTAL.OUT", "w") as f_output:
        f_output.write(str(res))

if __name__ == "__main__":
    main()
