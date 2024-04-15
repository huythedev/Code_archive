MOD = int(1e9 + 7)

def main():

    a, b, c, d = map(int, input().split())
    n, m, p, q = map(int, input().split())  

    result = pow(a, n, MOD) + pow(b, m, MOD) + pow(c, p, MOD) + pow(d, q, MOD)
    result %= MOD

    print(result)

if __name__ == "__main__":
    main()
