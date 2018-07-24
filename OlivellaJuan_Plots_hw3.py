import numpy as np
import matplotlib.pylab as plt
from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D

datos=np.genfromtxt("datos.dat")

t = datos[:,0]

x = datos[:,1]

y = datos[:,2]

z = datos[:,3]



fig = plt.figure()
ax = plt.axes(projection = '3d')
ax.plot3D(x, y, z, 'gray')
plt.title("x vs. y vs. z")
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
plt.savefig("3D.pdf")



plt.figure()

plt.subplot(2,2,1)
plt.plot(x,y)
plt.title("$(a)$ x vs. y")
plt.xlabel("$x$")
plt.ylabel("$y$")

plt.subplot(2,2,2)
plt.plot(y, z)
plt.title("$(b)$ y vs. z")
plt.xlabel("$y$")
plt.ylabel("$z$")


plt.subplot(2,2,3)
plt.plot(x,z)
plt.title("$(c)$ x vs. z")
plt.xlabel("$x$")
plt.ylabel("$z$")


plt.subplot(2,2,4)
plt.plot(t, y)
plt.title("$(d)$ t vs. y")
plt.xlabel("$t$")
plt.ylabel("$y$")

plt.tight_layout()
plt.savefig("plot.pdf")




datos1=np.genfromtxt("inicial.dat")

xinicial = datos1[:,0]

yinicial = datos1[:,1]

uinicial = datos1[:,2]


fig = plt.figure()
ax = fig.gca(projection='3d')
ax.plot_trisurf(xinicial, yinicial, uinicial, linewidth=0.2, antialiased=True, cmap=cm.jet)
plt.title("Grafica 3D de las condiciones iniciales para la membrana con bordes fijos")
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('U(X,Y)')
plt.savefig("inicial.pdf")


datos2=np.genfromtxt("60.dat")


x60 = datos2[:,0]

y60 = datos2[:,1]

u60 = datos2[:,2]


fig = plt.figure()
ax = fig.gca(projection='3d')
ax.plot_trisurf(x60, y60, u60, linewidth=0.2, antialiased=True, cmap=cm.jet)
plt.title("Grafica 3D de la membrana en el tiempo t = 0.3 s")
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('U(X,Y)')
plt.savefig("60.pdf")


datos3 = np.genfromtxt("corte.dat")


ycorte = datos3[:,0]

ucorte = datos3[:,1]


plt.figure()
plt.scatter(ycorte, ucorte, s = 2)
plt.title("Grafica de los cortes transversales en X = L/2")
plt.xlabel("Y")
plt.ylabel("Y(X,Y)")
plt.savefig("corte.pdf")



datos4=np.genfromtxt("inicial2.dat")

xinicial2 = datos4[:,0]

yinicial2 = datos4[:,1]

uinicial2 = datos4[:,2]


fig = plt.figure()
ax = fig.gca(projection='3d')
ax.plot_trisurf(xinicial2, yinicial2, uinicial2, linewidth=0.2, antialiased=True, cmap=cm.jet)
plt.title("Grafica 3D de las condiciones iniciales para la membrana con bordes libres")
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('U(X,Y)')
plt.savefig("inicial2.pdf")



datos5=np.genfromtxt("602.dat")

x602 = datos5[:,0]

y602 = datos5[:,1]

u602 = datos5[:,2]


fig = plt.figure()
ax = fig.gca(projection='3d')
ax.plot_trisurf(x602, y602, u602, linewidth=0.2, antialiased=True, cmap=cm.jet)
plt.title("Grafica 3D de la membrana en el tiempo t = 0.3 s para la membrana de bordes libres")
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('U(X,Y)')
plt.savefig("602.pdf")


datos6 = np.genfromtxt("corte2.dat")


ycorte2 = datos6[:,0]

ucorte2 = datos6[:,1]


plt.figure()
plt.scatter(ycorte2, ucorte2, s = 2)
plt.title("Grafica de los cortes transversales en X = L/2")
plt.xlabel("Y")
plt.ylabel("Y(X,Y)")
plt.savefig("corte2.pdf")







