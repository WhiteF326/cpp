import glob
import os
import subprocess

files = glob.glob("./testcases/in/*")
for file in files:
    print(os.path.basename(file))
    subprocess.run(
        ["./ans.exe"],
        stdin=open("./testcases/in/" + os.path.basename(file), "r"),
        stdout=open("./testcases/out/" + os.path.basename(file), "w")
    )
    subprocess.run(
        ["./slow.exe"],
        stdin=open("./testcases/in/" + os.path.basename(file), "r"),
        stdout=open("./testcases/out/slow_" + os.path.basename(file), "w")
    )