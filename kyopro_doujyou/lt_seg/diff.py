import glob
import os
import subprocess

files = glob.glob("./testcases/in/*")
for file in files:
    fast = open("./testcases/out/" + os.path.basename(file), "r")
    slow = open("./testcases/out/slow_" + os.path.basename(file), "r")
    if fast.read() != slow.read():
        print("\033[31m" + "FAIL" + "\033[0m")
        print(file)
