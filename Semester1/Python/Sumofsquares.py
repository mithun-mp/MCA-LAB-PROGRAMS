def sum_of_squares(lst):
    if not lst:
        return 0
    return lst[0] ** 2 + sum_of_squares(lst[1:])

n = int(input().strip())
L = [int(input().strip()) for _ in range(n)]
S = sum_of_squares(L)
print(L)
print(S)