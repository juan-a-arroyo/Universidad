from mpmath import mp

def calcular_pi(decimales):
    mp.dps = decimales  # Establece la precisión deseada
    pi = mp.pi  # Calcula Pi con la precisión especificada
    return pi

if __name__ == "__main__":
    num_decimales = int(input("Introduce el número de decimales de Pi que deseas calcular: "))
    pi = calcular_pi(num_decimales)
    print("Pi con", num_decimales, "decimales:", pi)
