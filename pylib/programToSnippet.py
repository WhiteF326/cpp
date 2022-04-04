# "mint1":{
#     "prefix": "mint1",
#     "body": [
#         "#define modv 1000000007",
#         "#define mint modint1000000007"
#     ]
# },

id = input("id: ")
prefix = input("prefix: ")
filename = input("filename: ")

f = open("../cpplib/{}.cpp".format(filename), "r")
lines = f.readlines()
f.close()

f = open("../cpplib/{}.json".format(filename), "w")

f.write("\"{}\":{{\n".format(id))
f.write("    \"prefix\": \"{}\",\n".format(prefix))
f.write("    \"body\": [\n")
for line in lines[:-1]:
    f.write("        \"{}\",\n".format(line.strip("\n")))
f.write("        \"{}\"\n".format(lines[-1].strip("\n")))
f.write("    ]\n")
f.write("}\n")
