import numpy as np

id = 839

for i in range(839, 839 + 179 + 1):
    print("#WAV" + np.base_repr(i, 36) + " Growl_{:03d}.wav".format(i - 839))