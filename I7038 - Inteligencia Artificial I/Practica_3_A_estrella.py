from collections import deque

# Definir el estado objetivo
goal_state = [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 0]]

# Funcion para encontrar la posicion del espacio vacio en el tablero
def find_blank(state):
    for i in range(3):
        for j in range(3):
            if state[i][j] == 0:
                return i, j

# Funcion para generar los sucesores de un estado dado
def successors(state):
    successors = []
    blank_row, blank_col = find_blank(state)
    
    # Mover hacia la izquierda
    if blank_col > 0:
        new_state = [row[:] for row in state]
        new_state[blank_row][blank_col], new_state[blank_row][blank_col - 1] = \
            new_state[blank_row][blank_col - 1], new_state[blank_row][blank_col]
        successors.append(new_state)
    
    # Mover hacia la derecha
    if blank_col < 2:
        new_state = [row[:] for row in state]
        new_state[blank_row][blank_col], new_state[blank_row][blank_col + 1] = \
            new_state[blank_row][blank_col + 1], new_state[blank_row][blank_col]
        successors.append(new_state)
    
    # Mover hacia arriba
    if blank_row > 0:
        new_state = [row[:] for row in state]
        new_state[blank_row][blank_col], new_state[blank_row - 1][blank_col] = \
            new_state[blank_row - 1][blank_col], new_state[blank_row][blank_col]
        successors.append(new_state)
    
    # Mover hacia abajo
    if blank_row < 2:
        new_state = [row[:] for row in state]
        new_state[blank_row][blank_col], new_state[blank_row + 1][blank_col] = \
            new_state[blank_row + 1][blank_col], new_state[blank_row][blank_col]
        successors.append(new_state)
    
    return successors

# Funcion para calcular la distancia de Manhattan entre dos posiciones
def manhattan_distance(pos1, pos2):
    return abs(pos1[0] - pos2[0]) + abs(pos1[1] - pos2[1])

# Funcion para calcular la heuristica (distancia de Manhattan)
def heuristic(state):
    total_distance = 0
    for i in range(3):
        for j in range(3):
            if state[i][j] != 0:
                goal_pos = ((state[i][j] - 1) // 3, (state[i][j] - 1) % 3)
                total_distance += manhattan_distance((i, j), goal_pos)
    return total_distance

# Funcion para verificar si un estado es el objetivo
def is_goal(state):
    return state == goal_state

# Algoritmo A*
def a_star(initial_state):
    frontier = [(initial_state, [])]  # Prioridad basada en f(n) = g(n) + h(n), donde g(n) es la profundidad y h(n) es la heurística
    explored = set()

    while frontier:
        frontier.sort(key=lambda x: len(x[1]) + heuristic(x[0]))  # Ordenar la frontera por f(n)
        state, path = frontier.pop(0)
        if is_goal(state):
            return path
        explored.add(tuple(map(tuple, state)))
        for successor in successors(state):
            if tuple(map(tuple, successor)) not in explored:
                frontier.append((successor, path + [successor]))

# Funcion para imprimir el tablero
def print_board(state):
    for row in state:
        print(row)

# Funcion para generar un estado inicial aleatorio
def random_initial_state():
    import random
    numbers = list(range(9))
    random.shuffle(numbers)
    return [numbers[i:i+3] for i in range(0, 9, 3)]

# Estado inicial aleatorio
initial_state = random_initial_state()

print("Estado inicial:")
print_board(initial_state)

# Buscar solucion utilizando A*
solution = a_star(initial_state)

if solution:
    print("\nSe encontro una solucion:")
    for i, state in enumerate(solution):
        print(f"Paso {i + 1}:")
        print_board(state)
        print()
else:
    print("\nNo se encontro una solución.")
