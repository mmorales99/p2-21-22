import numpy as np

def L_n(func,a,b,n):
    list = np.arange(a,b,n)
    f = []
    for j in list:
        f.append(func(j))
    integral = map(lambda x:x*n,f)
    sum = 0
    for i in integral:
        sum+=i
    return sum

def R_n(func,a,b,n):
    list = np.arange(a+n,b+n,n)
    f = []
    for j in list:
        f.append(func(j))
    integral = map(lambda x:x*n,f)
    sum = 0
    for i in integral:
        sum+=i
    return sum

def Reiman_sum(func,a,b,n):
    Ln = L_n(func,a,b,n)
    Rn = R_n(func,a,b,n)
    result = (Ln,Rn)
    return result

def trapezoidal(func,a,b,n):
    h = (b-a)/float(n)
    xval = [a+i*h for i in range(1,n)]
#   yval = list(map(func,xvals))
    func = np.vectorize(func)
    yval = func(xval)
    return sum(yval) + 0.5*(func(a)+func(b))*h

from sympy.integrate import quad, dquad

f = lambda x: np.sin(x)**2 * x**2 * 10**-x
n=100
a=0
b=np.pi
h = (b-a)/float(n)
Int = Reiman_sum(f,a,b,h)
print(Int)