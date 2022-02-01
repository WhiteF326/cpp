k = int(input())
ans = bin(k)[2:]
print("".join(["2" if elm == '1' else "0" for elm in list(ans)]))