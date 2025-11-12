import numpy as np
import matplotlib.pyplot as plt

# Funcion Objetivo
def funcion_objetivo(dimensiones):
    # Calcula el peso de la viga (ejemplo simplificado)
    return dimensiones[0] * dimensiones[1] * dimensiones[2]

# Restricciones
def restricciones(dimensiones):
    # Requisitos minimos de resistencia y rigidez (ejemplo simplificado)
    return all(d >= 0.01 for d in dimensiones)

# Algoritmo Harmony Search
def harmony_search(objetivo, restricciones, tamano_memoria=100, tasa_ajuste=0.3, max_iteraciones=1000):
    memoria_armonia = np.random.rand(tamano_memoria, 3)
    mejor_solucion = None
    mejor_fitness = float('inf')
    historial_fitness = []

    for _ in range(max_iteraciones):
        nueva_armonia = np.random.rand(3)
        
        # Ajuste de tono
        if np.random.rand() < tasa_ajuste:
            nueva_armonia += np.random.rand(3) * 0.01
        
        # Verificar restricciones
        if restricciones(nueva_armonia):
            nuevo_fitness = objetivo(nueva_armonia)
            if nuevo_fitness < mejor_fitness:
                mejor_fitness = nuevo_fitness
                mejor_solucion = nueva_armonia
            
            # Actualizar memoria de armonia
            peor_idx = np.argmax([objetivo(h) for h in memoria_armonia])
            if objetivo(memoria_armonia[peor_idx]) > nuevo_fitness:
                memoria_armonia[peor_idx] = nueva_armonia
        
        historial_fitness.append(mejor_fitness)

    return mejor_solucion, mejor_fitness, historial_fitness

# Ejecucion del algoritmo
solucion, fitness, historial = harmony_search(funcion_objetivo, restricciones)

# Resultados
print(f"Mejor solucion: {solucion}")
print(f"Mejor fitness: {fitness}")

# Grafica de convergencia
plt.plot(historial)
plt.xlabel('Iteracion')
plt.ylabel('Mejor Fitness')
plt.title('Convergencia del Harmony Search')
plt.show()
