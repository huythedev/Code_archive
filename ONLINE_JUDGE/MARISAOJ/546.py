from itertools import permutations

n, k = map(int, input().split())
nums = list(range(1, n + 1))

for perm in permutations(nums, k):
    print(' '.join(map(str, perm)))