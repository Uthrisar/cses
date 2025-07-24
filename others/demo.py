import numpy as np
import matplotlib.pyplot as plot
# Get x values of the sine wave
time = np.arange(0, 10, 0.1)
# Amplitude of the sine wave is sine of a variable like time
amplitude = np.sin(time)
# Plot a sine wave using time and amplitude obtained for the sine wave
plot.plot(time, amplitude)
plot.show()