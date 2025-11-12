import networkx as nx
import matplotlib.pyplot as plt
import random

# Generar el grafo
grafo = nx.Graph()

# Agregar 10 nodos al grafo
grafo.add_nodes_from(range(1, 11))

# Agregar caminos con pesos aleatorios
for nodo in range(1, 11):
    num_caminos = random.randint(2, 5)  # Entre 2 y 5 caminos por nodo
    for _ in range(num_caminos):
        nodo_destino = random.randint(1, 10)
        if nodo_destino != nodo and not grafo.has_edge(nodo, nodo_destino):
            peso = random.randint(5, 20)  # Peso aleatorio entre 5 y 20
            grafo.add_edge(nodo, nodo_destino, weight=peso)

# Calcular la rutaoptima usando el algoritmo del TSP
ruta_optima = list(nx.approximation.traveling_salesman_problem(grafo, cycle=True))

# Agregar el nodo inicial al final de la ruta para regresar al punto de inicio
ruta_optima.append(ruta_optima[0])

# Visualizar el grafo con los nodos mas separados
pos = nx.spring_layout(grafo, scale=3)  # Ajuste del parametro scale

# Dibujar nodos y etiquetas de pesos de aristas
nx.draw_networkx_nodes(grafo, pos, node_size=700, node_color='lightblue')
nx.draw_networkx_labels(grafo, pos, font_size=12, font_family='sans-serif')
nx.draw_networkx_edges(grafo, pos)

# Agregar etiquetas de pesos de aristas
pesos = nx.get_edge_attributes(grafo, 'weight')
nx.draw_networkx_edge_labels(grafo, pos, edge_labels=pesos, font_color='black')

# Dibujar la rutaoptima con una linea roja
nx.draw_networkx_edges(grafo, pos, edgelist=[(ruta_optima[i], ruta_optima[i+1]) for i in range(len(ruta_optima)-1)], edge_color='r', width=2)

plt.title('Ruta mas optima en el grafo con 10 nodos')
plt.axis('off')
plt.show()

# Mostrar la rutaoptima
print("Ruta optima:", ruta_optima)
