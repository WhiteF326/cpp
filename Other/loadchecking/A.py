import random


ans = [i + 1 for i in range(20)]
random.shuffle(ans)
print("\n".join(map(str, ans)))
