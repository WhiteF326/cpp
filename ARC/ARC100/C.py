n = int(input())
a = list(map(int, input().split()))
a = sorted([a[elm] - elm - 1 for elm in list(range(n))])
b = a[n // 2] if n % 2 else (a[n // 2 - 1] + a[n // 2]) // 2
print(sum([abs(elm - b) for elm in a]))
