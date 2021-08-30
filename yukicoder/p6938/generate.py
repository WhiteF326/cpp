import random
import time

for i in range(5):
    random.seed(time.time())
    f = open("testcases/04_ran2_" + str(i) + ".txt", mode='w')
    n = int(random.uniform(1, 1<<62))
    f.write(str(n * 468))
    f.write("\n")
    time.sleep(1)