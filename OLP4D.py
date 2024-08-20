def sumcs(n):
    res = 0
    while n > 0:
        res += n % 10
        n //= 10
    return res

def main():
    T = 2
    while T > 0:
        n, k = map(int, input().split())

        res = 0
        for i in range(1, n // k + 1):
            res += sumcs(i * k)

        print(res)
        T -= 1

if __name__ == "__main__":
    main()