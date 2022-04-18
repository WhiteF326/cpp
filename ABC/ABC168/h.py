f = open("./header.txt", "r")
r = f.readlines()
f.close()

w = ["\"" + i.replace("\n", "") + "\"," for i in r]
f = open("./header.txt", "w")
f.write("".join(w))
f.close()
