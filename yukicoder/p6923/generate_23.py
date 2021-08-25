import random, time, queue

infl = 1000000000

for i in range(3):
    random.seed(time.time())
    f = open("testcases/06_t_" + str(i) + ".txt", mode='w')
    n = 10
    m = 100
    a = int(random.uniform(1, n))
    b = int(random.uniform(1, n))

    pathlist = []
    for i in range(n):
        pathlist.append(i)
        pathlist.append(i)
    for _ in range(2 * m - 2 * n):
        pathlist.append(int(random.uniform(1, n)))
    random.shuffle(pathlist)
    paths = set()
    for i in range(m):
        x = pathlist[i * 2]
        y = pathlist[i * 2 + 1]
        if x > y:
            x, y = y, x
        if x == y:
            continue
        paths.add(x * n + y)
    paths = list(paths)
    
    # solve
    g = [[] for _ in range(n)]
    for i in range(len(paths)):
        x, y = paths[i] // n, paths[i] % n
        g[x].append(y)
        g[y].append(x)

    q = queue.Queue()
    q.put(a)
    depth = [infl for _ in range(n)]
    depth[a] = 0
    visited = [False for _ in range(n)]
    visited[a] = True

    while not q.empty():
        dest = q.get()
        for v in g[dest]:
            if not visited[v]:
                visited[v] = True
                depth[v] = depth[dest] + 1
                q.put(v)
    
    # definite k
    det = int(random.uniform(0, 2))
    if det % 2:
        diff = int(random.uniform(1, m - depth[b]))
    else:
        print("f")
        diff = 0
    k = diff + depth[b]
    
    f.write(" ".join(str(elm) for elm in [n, len(paths), k]))
    f.write("\n")
    f.write(" ".join(str(c) for c in [a + 1, b + 1]))
    f.write("\n")
    for s in paths:
        f.write(" ".join(str(elm + 1) for elm in [s // n, s % n]))
        f.write("\n")
