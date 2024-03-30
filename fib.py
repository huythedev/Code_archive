import sys
import gmpy2
from gmpy2 import mpz
import time

limit = 0
i = 0

def fibonacci(limit):
    a, b, c = mpz(1), mpz(0), mpz(0)
    start_time = time.time()

    for i in range(limit):
        # Perform the Fibonacci Calculation
        c = a + b
        a, b = b, c

    end_time = time.time()

    # Print the results
    print(f"Fibonacci Number {i+1}: {b}")

    # Print time taken
    time_taken = end_time - start_time
    print(f"Calculation Time: {time_taken} seconds")

if __name__ == "__main__":
    # Get User Input
    if len(sys.argv) != 2:
        print("Improper input. Exiting.")
        sys.exit(1)

    limit = int(sys.argv[1])

    # Calculate Fibonacci
    fibonacci(limit)
