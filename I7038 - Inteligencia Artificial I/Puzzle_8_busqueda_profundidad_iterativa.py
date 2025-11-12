from collections import deque
import random

# Definir movimientos posibles
MOVES = {
    'U': (-1, 0),  # Up
    'D': (1, 0),   # Down
    'L': (0, -1),  # Left
    'R': (0, 1)    # Right
}

# Funcion para encontrar la posicion del espacio en blanco en el tablero
def find_blank(board):
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == 0:
                return i, j

# Funcion para generar un estado inicial aleatorio
def generate_initial_state():
    numbers = list(range(9))
    random.shuffle(numbers)
    return [numbers[i:i+3] for i in range(0, 9, 3)]

# Funcion para comprobar si el tablero esta en el estado objetivo
def is_goal_state(board):
    return board == [[1, 2, 3], [4, 5, 6], [7, 8, 0]]

# Funcion para aplicar un movimiento al tablero
def apply_move(board, move):
    blank_row, blank_col = find_blank(board)
    dr, dc = MOVES[move]
    new_blank_row, new_blank_col = blank_row + dr, blank_col + dc
    if 0 <= new_blank_row < 3 and 0 <= new_blank_col < 3:
        board[blank_row][blank_col], board[new_blank_row][new_blank_col] = \
            board[new_blank_row][new_blank_col], board[blank_row][blank_col]
        return board
    else:
        return None  # Movimiento no valido

# Busqueda en profundidad iterativa
def iterative_depth_first_search(initial_state):
    max_depth = 1
    while True:
        result = depth_limited_search(initial_state, max_depth)
        if result is not None:
            return result
        max_depth += 1

# Busqueda en profundidad limitada
def depth_limited_search(initial_state, max_depth):
    stack = deque([(initial_state, [], 0)])  # Inicializar la pila con el estado inicial, la ruta vacía y la profundidad
    visited = set()  # Conjunto para almacenar los estados visitados

    while stack:
        state, path, depth = stack.pop()  # Sacar el ultimo estado, su ruta y la profundidad actual
        if depth > max_depth:
            continue  # No explorar mas alla de la profundidad maxima
        if is_goal_state(state):
            return path  # Devolver la ruta si el estado es el objetivo
        visited.add(tuple(map(tuple, state)))  # Agregar el estado actual al conjunto de visitados

        # Generar sucesores y agregarlos a la pila si no han sido visitados
        for move in MOVES:
            new_state = apply_move([row[:] for row in state], move)
            if new_state and tuple(map(tuple, new_state)) not in visited:
                stack.append((new_state, path + [move], depth + 1))

    return None  # No se encontro solucion dentro de la profundidad maxima

# Estado inicial aleatorio
initial_state = generate_initial_state()
print("Estado inicial:")
for row in initial_state:
    print(row)

# Resolver utilizando busqueda en profundidad iterativa
solution = iterative_depth_first_search(initial_state)
if solution:
    print("\nSolucion encontrada con {} movimientos:".format(len(solution)))
    # Aplicar movimientos para mostrar la solucion
    current_state = initial_state
    for i, move in enumerate(solution):
        print("Movimiento {}:".format(i+1))
        current_state = apply_move(current_state, move)
        for row in current_state:
            print(row)
else:
    print("\nNo se encontro solucion.")
