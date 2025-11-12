import os
os.system("CLS")
def factorial(numero):
    fact=1
    for n in range(1,numero+1):
        fact=fact*n
    return fact

limite=int(input("Ingrese el limite del ciclo: "))
n=0
e=0
while n<limite:
    e+=1/factorial(n)
    n+=1
print("El numero e es:",e)