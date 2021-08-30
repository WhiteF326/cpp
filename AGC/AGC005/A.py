stack = []

x = input()
for c in list(x):
    if len(stack):
        if stack[-1] == 'S' and c == 'T':
            stack.pop()
        else:
            stack.append(c)
    else:
        stack.append(c)

print(len(stack))