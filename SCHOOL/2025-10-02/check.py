import random
import subprocess

def gen_input(n, m):
    with open("FACTDIV.INP", "w") as f:
        f.write(f"{n} {m}\n")

def run_file(filename):
    subprocess.run(["python3", filename], check=True)
    with open("FACTDIV.OUT", "r") as f:
        return f.read().strip()

def main():
    for _ in range(10):  # run 10 random tests
        n = random.randint(1, 10**6)
        m = random.randint(1, 10**6)
        gen_input(n, m)

        out1 = run_file("FACTDIV.py")
        out2 = run_file("FACTDIV2.py")

        if out1 != out2:
            print("Mismatch!")
            print(f"n={n}, m={m}")
            print(f"FACTDIV.py  -> {out1}")
            print(f"FACTDIV2.py -> {out2}")
            return

    print("All tests passed ✅")

if __name__ == "__main__":
    main()
