import sys
sys.setrecursionlimit(1 << 20)

n, x = map(int, input().split())
x -= 1

if x == 0:
    print(0)
    exit()

totalSize = [0] * (n + 1)
totalSize[0] = 1
for i in range(1, n + 1):
    totalSize[i] = totalSize[i - 1] * 2 + 3
puttyCount = [0] * (n + 1)
puttyCount[0] = 1
for i in range(1, n + 1):
    puttyCount[i] = puttyCount[i - 1] * 2 + 1
firstPutty = [0, 1, 2, 3, 3]

def dfs(depth, pos, sum):
    if depth == 1:
        print(sum + firstPutty[pos])
        return
    else:
        burgerCount = [
            [1, 0],
            [totalSize[depth - 1], puttyCount[depth - 1]],
            [1, 1],
            [totalSize[depth - 1], puttyCount[depth - 1]],
            [1, 0]
        ]
        totalSum = 0
        puttySum = 0
        for e in burgerCount:
            totalSum += e[0]
            puttySum += e[1]
            if totalSum > pos + 1:
                dfs(depth - 1, pos - totalSum + e[0], sum + puttySum - e[1])
                break
            elif totalSum == pos + 1:
                print(sum + puttySum)
                return

dfs(n, x, 0)
