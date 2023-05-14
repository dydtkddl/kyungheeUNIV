import sympy as sy
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

n = sy.Symbol("n")
x = sy.Symbol("x")
t = sy.Symbol("t")
a = 1000
Ti = 30
Ts = 34
integrate_expr = sy.integrate(sy.exp(-(n**2)))
result = integrate_expr.subs(n,n)-integrate_expr.subs(n,0)
new_result = result.subs(n,x/(2*(a*t)**(sy.Rational(1,2))))
new_result = (Ti-Ts)*(2/(3.14)**sy.Rational(1,2))*new_result+Ts
x_ = np.linspace(0,500,100)
time = np.linspace(0,5000,100)

x_, time = np.meshgrid(x_, time)
real_mat = np.zeros_like(x_, dtype=float)
imag_mat = np.zeros_like(x_, dtype=float)
for i in range(100):
    for j in range(100):
        xx = x_[i][j]
        tt = time[i][j]
        result = new_result.subs({x : xx, t : tt})
        real_mat[i][j] = sy.re(result)
        imag_mat[i][j] = sy.im(result)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
surf = ax.plot_surface(x_, time, real_mat, cmap='viridis')
plt.show()