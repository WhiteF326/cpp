import subprocess

# f = open("random_01.txt", "r")
cmd = "./F < random_01.txt"
subprocess.run(cmd, shell=True)
