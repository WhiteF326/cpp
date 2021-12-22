l = sorted(
    [
        [10 - elm % 10 if elm % 10 != 0 else 0, elm]
        for elm in (int(input()) for _ in range(5))
    ]
)
print(sum(map(sum, l)) - l[4][0])