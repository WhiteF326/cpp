import os

for i in range(100):
    os.system(
        "python -u generator.py " + str(i) + " > testcases/seed" + str(i) + ".txt"
    )