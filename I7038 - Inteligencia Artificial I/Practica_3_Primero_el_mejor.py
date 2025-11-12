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

# Funcion para verificar si un estado es el objetivo
def is_goal(state):
    return state == goal_state

# Funcion de evaluacion heuristica - distancia de Manhattan
def manhattan_distance(state):
    distance = 0
    for i in range(3):
        for j in range(3):
            if state[i][j] != 0:
                target_row, target_col = (state[i][j] - 1) // 3, (state[i][j] - 1) % 3
                distance += abs(i - target_row) + abs(j - target_col)
    return distance

# Algoritmo de busqueda de Primero el Mejor
def best_first_search(initial_state):
    frontier = deque([(manhattan_distance(initial_state), initial_state)])  # Usaremos una cola de prioridad como nuestra "frontera"
    explored = set()
    step = 1

    while frontier:
        frontier = deque(sorted(frontier))  # Ordenamos la frontera segun la heuristica
        _, state = frontier.popleft()  # Sacamos el primer elemento de la cola, el de menor costo
        print("Movimiento", step, ":")
        print_board(state)
        if is_goal(state):
            return state
        explored.add(tuple(map(tuple, state)))
        for successor in successors(state):
            if tuple(map(tuple, successor)) not in explored:
                frontier.append((manhattan_distance(successor), successor))
        if step == 60:
            print("Se han realizado 60 movimientos. No se encontró solución.")
            return None
        step += 1

# Funcion para imprimir el tablero
def print_board(state):
    for row in state:
        print(row)
    print()

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

# Buscar solucion utilizando busqueda de Primero el Mejor
solution = best_first_search(initial_state)

if solution:
    print("\nSe encontro una solucion:")
    print_board(solution)
