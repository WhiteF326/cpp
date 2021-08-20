import glob
import os

l = glob.glob("**/*.exe", recursive=True)
for f in l:
  os.remove(f)