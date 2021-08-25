import random, time

for i in range(20):
    random.seed(time.time())
    f = open("testcases/02_body_" + str(i) + ".txt", mode='w')
    n = int(random.uniform(1, 1000))
    f.write(str(n) + "\n")
    time.sleep(1)