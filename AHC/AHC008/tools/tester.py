import subprocess
import sys


command = "./b.out"

for i in range(1000):
    print("Test #" + str(i) + " ", end="")
    sys.stdout.flush()
    subprocess.run(
        "target/release/tester {} < in/{}.txt > out/{}.txt".format(command, str(i).zfill(4), str(i).zfill(4)), shell=True
    )
