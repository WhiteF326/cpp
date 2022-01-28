import math

st = set()
n = int(input())


for i in range(2, int(math.ceil(math.sqrt(n))) + 1):
    j = 2
    while i ** j <= n:
        st.add(i ** j)
        j += 1

print(n - len(st))