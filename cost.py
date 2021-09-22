import matplotlib.pyplot as plt

x = [(10 + 5 * n + 2 * (14 - n)) for n in range(2, 5)]
y = list(range(2, 5))
plt.plot(y, x)
plt.show()