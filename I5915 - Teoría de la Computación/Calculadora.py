print("CALCULADORA")
while True:
    operacion = input("¿Qué operación quieres realizar? (+, -, *, /): ")
    while operacion != "+" and operacion != "-" and operacion != "*" and operacion != "/":
        print("Operación inválida")
        operacion = input("¿Qué operación quieres realizar? (+, -, *, /): ")
    num1 = float(input("Ingresa el primer número: "))
    num2 = float(input("Ingresa el segundo número: "))
    if operacion == "+":
        print("El resultado es: ", num1 + num2)
    elif operacion == "-":
        print("El resultado es: ", num1 - num2)
    elif operacion == "*":
        print("El resultado es: ", num1 * num2)
    elif operacion == "/":
        if num2 == 0:
            print("Indefinido (No se puede dividir entre 0")
        else:
            print("El resultado es: ", num1 / num2)
    continuar = input("¿Deseas realizar otra operación? (S/N): ")
    if continuar.upper() != "S":
        break