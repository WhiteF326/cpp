n = int(input())
p = list(map(int, input().split()))
q = list(map(int, input().split()))

ans = 0
for i in range(1 << n):
    st = set()
    for j in range(n):
        if i & (1 << j):
            st.add(p[j])
            st.add(q[j])
    
    if len(st) == n:
        ans += 1
        # print(st)
        print(bin(i)[2:].zfill(n))

print(ans)