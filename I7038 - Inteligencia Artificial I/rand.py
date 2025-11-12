import random
import string

def generar_letras_aleatorias(limite):
    letras_generadas = ''
    for _ in range(limite):
        letra_aleatoria = random.choice(string.ascii_lowercase)  # Escoge una letra minúscula aleatoria
        letras_generadas += letra_aleatoria
    return letras_generadas

if __name__ == "__main__":
    limite_letras = int(input("Introduce el número de letras minúsculas que deseas generar: "))
    letras_generadas = generar_letras_aleatorias(limite_letras)

    # Guarda las letras generadas en un archivo de texto
    nombre_archivo = "letras_generadas.txt"
    with open(nombre_archivo, "w") as archivo:
        archivo.write(letras_generadas)

    print("Las letras generadas han sido guardadas en el archivo:", nombre_archivo)
