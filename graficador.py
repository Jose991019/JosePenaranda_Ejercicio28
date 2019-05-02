import numpy as np 
import matplotlib.pyplot as plt
import matplotlib.cm as cm

Z = np.loadtxt('datos.txt')
len(Z)
X = np.array(range(201))
Y = np.array(range(201))

fig = plt.figure(figsize = (15,5))
plt.subplot(1,2,1)
n_points = int(np.sqrt(len(Z)))
grid = np.reshape(Z, (201, 201))
plt.imshow(grid)
plt.xlabel("Indice X")
plt.ylabel("Indice T")
plt.colorbar(label="Temperatura")
plt.subplot(1,2,2)
y1 = Z[0,:]
y2 = Z[-1,:]
plt.plot(X,y1)
plt.plot(X,y2)
plt.xlabel("Indice X")
plt.ylabel("Temperatura")
plt.savefig('Resultado.png')