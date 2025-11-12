nombre = input("Cual es tu nombre: ")
edad = input("Cual es tu edad: ")
edad=int(edad)
print("Hola soy", nombre, "y tengo", edad, "años.")
if edad >= 18:
    print("Eres Mayor de Edad")
else:
    print("Eres menor de edad")