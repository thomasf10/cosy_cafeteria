import numpy as np
import matplotlib.pyplot as plt
import matplotlib as matplot

filename = '../Polarity_protection.txt'

# data inlezen exclusief memcopy
data = np.loadtxt(filename, delimiter='\t', skiprows=1)    # geef de juiste filenaam mee
tijd = data[:, 0] * 1000000
vin = data[:, 1]
vout = data[:, 2]

saveFig = False      # om op te slaan

name = 'Transient response positive input pulse'
plt.figure(name)
plt.title(name)
plt.plot(tijd, vin, label='V_in')
plt.plot(tijd, vout, label='V_out',color='r')
plt.legend(loc='upper right')
plt.xlabel('Time [µs]')
plt.ylabel('Voltage [V]')
plt.ylim([-0.5,4.5])
plt.grid(True,which='both')
if saveFig==True:
    plt.savefig(f'{name}.eps', format='eps')
plt.show()