import random, time

def fullxor(ary: list[int]):
    ret = 0
    for i in ary:
        ret ^= i
    return ret

# for i in range(5):
#     random.seed(time.time())
#     f = open("testcases/04_big_" + str(i) + ".txt", mode='w')
#     size = int(random.uniform(50 + 10 * i, 60 + 10 * i))
#     while 1:
#         a = [int(random.uniform(1, 1000)) for _ in range(size - 1)]
#         if fullxor(a) <= 1000:
#             a.append(fullxor(a))
#             break
#     f.write(str(size) + "\n")
#     f.write(" ".join(str(elm) for elm in a))
#     time.sleep(1)

for i in range(5):
    random.seed(time.time())
    f = open("testcases/05_same_" + str(i) + ".txt", mode='w')
    size = int(random.uniform(1, 50)) * 2
    x = int(random.uniform(1, 1000))
    a = [x for _ in range(size)]
    f.write(str(size) + "\n")
    f.write(" ".join(str(elm) for elm in a))
    time.sleep(1)