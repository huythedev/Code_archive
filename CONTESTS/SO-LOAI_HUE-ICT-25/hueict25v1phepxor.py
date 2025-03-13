MOD = 10**9 + 7

def calc(val, p):
    if val < 0:
        return 0
    res = ((val + 1) // (1 << (p + 1))) * (1 << p)
    res += max(0, ((val + 1) % (1 << (p + 1)) - (1 << p)))
    return res

a, b = map(int, input().split())
if b > 1e30:
    print(0)
    exit()
total = b - a + 1
mod_total = total % MOD
square_mod = (mod_total * mod_total) % MOD

max_pos = 0
if b > 0:
    max_pos = max(max_pos, b.bit_length())
if a > 0:
    prev_num = a - 1
    if prev_num > 0:
        max_pos = max(max_pos, prev_num.bit_length())
max_pos = max(max_pos, 1000) 

res = 0
for j in range(max_pos + 1):
    r = calc(b, j)
    if a == 0:
        l = 0
    else:
        l = calc(a - 1, j)

    curr_diff = r - l
    diff_mod = curr_diff % MOD

    tmp = (mod_total - diff_mod) % MOD
    tmp2 = (2 * diff_mod * tmp) % MOD

    tmp3 = (2 * tmp2) % MOD
    tmp3 = (tmp3 * ((square_mod - tmp2) % MOD)) % MOD

    power_val = pow(2, j, MOD)
    curr_value = (tmp3 * power_val) % MOD

    res = (res + curr_value) % MOD

print(res)