import re

s = input()
if re.fullmatch('[A-Z]*C[A-Z]*F[A-Z]*', s):
  print("Yes")
else:
  print ("No")