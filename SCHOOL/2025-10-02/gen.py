import os
import random
import subprocess
import shutil

PROBLEM = "FACTDIV"
TOTAL_TESTS = 50

def gen_input(n, m, path):
    inp_path = os.path.join(path, f"{PROBLEM}.INP")
    with open(inp_path, "w") as f:
        f.write(f"{n} {m}\n")
    return inp_path

def run_solution(inp_path, out_path):
    # Copy input to root so reference solution can read it
    shutil.copy(inp_path, f"{PROBLEM}.INP")

    # Run reference solution FACTDIV.py
    subprocess.run(["python3", f"{PROBLEM}.py"], check=True)

    # Move produced output into subfolder
    shutil.move(f"{PROBLEM}.OUT", out_path)

def main():
    if not os.path.exists(PROBLEM):
        os.makedirs(PROBLEM)

    for t in range(1, TOTAL_TESTS + 1):
        test_folder = os.path.join(PROBLEM, f"test{t:03d}")
        os.makedirs(test_folder, exist_ok=True)

        if 1 <= t <= 20:
            n = random.randint(1, 20)
            m = random.randint(1, 20)
        elif 21 <= t <= 40:
            n = random.randint(1, 3000)
            m = random.randint(1, 3000)
        else:  # 41–50
            n = random.randint(1, 10**6)
            m = random.randint(1, 10**6)

        # Generate input
        inp_path = gen_input(n, m, test_folder)

        # Generate output using reference solution
        out_path = os.path.join(test_folder, f"{PROBLEM}.OUT")
        run_solution(inp_path, out_path)

        print(f"Generated test{t:03d}: n={n}, m={m}")

if __name__ == "__main__":
    main()
