import math
import os

def cuadrado (lado):
    area=lado*lado
    return area

def triangulo (base, altura):
    area=(base*altura)/2
    return area

def circulo (radio):
    area=math.pi*radio**2
    return area
opc=0
while(opc!=4):
    os.system("CLS")
    print("CALCULADORA DE AREA\n\n")
    print("1. Cuadrado\n2. Triangulo\n3. Circulo\n4. Salir")
    opc=int(input("Opcion: "))
    if opc==1:
        lado=int(input("Ingrese el lado del Cuadrado: "))
        print("El area del cuadrado es:",cuadrado(lado))
    if opc==2:
        base=int(input("Ingrese la base del triangulo: "))
        altura=int(input("Ingrese la altura del triangulo: "))
        print("El area del triangulo es:",triangulo(base,altura))
    if opc==3:
        radio=int(input("Ingrese el radio del circulo: "))
        print("El area del circulo es:",circulo(radio))
    os.system("PAUSE")





