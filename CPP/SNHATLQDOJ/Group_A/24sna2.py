def main():
    T, D, Q, I, K = map(int, input().split())

    if D == I:
        print(abs(T - Q))
    else:
        print(abs((T + D * K) - (Q + I * K)))

if __name__ == "__main__":
    main()
