import pygame
import sys
import random
import math
from collections import deque

# Inicializar Pygame
pygame.init()

# Definir colores
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

# Tamaño de la pantalla
WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Laberinto con Formas como Obstáculos")

# Clase para representar obstáculos poligonales
class Obstacle(pygame.sprite.Sprite):
    def __init__(self, shape, color, position):
        super().__init__()
        self.shape = shape
        self.color = color
        self.position = position
        self.create_shape()

    def draw_x(self, size_multiplier):
        rect = self.image.get_rect()
        pygame.draw.line(self.image, (255, 0, 0), rect.topleft, rect.bottomright, 2)
        pygame.draw.line(self.image, (255, 0, 0), rect.bottomleft, rect.topright, 2)

    def draw_circle(self, size_multiplier):
        pygame.draw.circle(self.image, (255, 0, 0), (25 * size_multiplier, 25 * size_multiplier), 15)

    def create_shape(self):
        size_multiplier = 3  # Puedes ajustar este valor según tu preferencia

        if self.shape == "square":
            self.image = pygame.Surface((50 * size_multiplier, 50 * size_multiplier), pygame.SRCALPHA)
            pygame.draw.rect(self.image, self.color, self.image.get_rect())
        elif self.shape == "star":
            self.image = pygame.Surface((50 * size_multiplier, 50 * size_multiplier), pygame.SRCALPHA)
            self.draw_star(size_multiplier)
        elif self.shape == "triangle":
            self.image = pygame.Surface((50 * size_multiplier, 50 * size_multiplier), pygame.SRCALPHA)
            self.draw_triangle(size_multiplier)
        elif self.shape == "rhombus":
            self.image = pygame.Surface((50 * size_multiplier, 50 * size_multiplier), pygame.SRCALPHA)
            self.draw_rhombus(size_multiplier)
        elif self.shape == "destination_x":
            self.image = pygame.Surface((30, 30), pygame.SRCALPHA)
            self.draw_x(1)  # El tamaño de la "X" es más pequeño, puedes ajustar según sea necesario
        elif self.shape == "origin_circle":
            self.image = pygame.Surface((50 * size_multiplier, 50 * size_multiplier), pygame.SRCALPHA)
            self.draw_circle(size_multiplier)

        self.rect = self.image.get_rect(center=self.position)

    def draw_star(self, size_multiplier):
        cx, cy = 25 * size_multiplier, 25 * size_multiplier  # Centro de la estrella
        length = 15 * size_multiplier  # Longitud de los lados de los triángulos

        # Primer triángulo (punta hacia arriba)
        pygame.draw.polygon(self.image, self.color, [(cx, cy - length), (cx + math.sqrt(3) * length / 2, cy + length / 2),
                                                     (cx - math.sqrt(3) * length / 2, cy + length / 2)])

        # Segundo triángulo (punta hacia abajo)
        pygame.draw.polygon(self.image, self.color, [(cx, cy + length), (cx + math.sqrt(3) * length / 2, cy - length / 2),
                                                     (cx - math.sqrt(3) * length / 2, cy - length / 2)])

    def draw_triangle(self, size_multiplier):
        pygame.draw.polygon(self.image, self.color, [(25 * size_multiplier, 0), (50 * size_multiplier, 50 * size_multiplier),
                                                     (0, 50 * size_multiplier)])

    def draw_rhombus(self, size_multiplier):
        pygame.draw.polygon(self.image, self.color, [(25 * size_multiplier, 0), (50 * size_multiplier, 25 * size_multiplier),
                                                     (25 * size_multiplier, 50 * size_multiplier),
                                                     (0, 25 * size_multiplier)])

# Función para generar obstáculos aleatorios
def generate_obstacles():
    obstacles = pygame.sprite.Group()
    shapes = ["square", "star", "triangle", "rhombus"]
    min_distance = 20  # Distancia mínima entre las figuras

    grid_size = 50  # Tamaño de la cuadrícula para posicionar las figuras
    grid_rows = HEIGHT // grid_size
    grid_cols = WIDTH // grid_size

    destination_position = (grid_size // 2, grid_size // 2)

    # Asegurarse de que la posición de la "X" esté libre de obstáculos
    while any(obstacle.rect.colliderect(pygame.Rect(destination_position, (50, 50))) for obstacle in obstacles):
        destination_position = (random.randint(0, WIDTH), random.randint(0, HEIGHT))

    destination_obstacle = Obstacle("destination_x", (255, 0, 0), destination_position)
    obstacles.add(destination_obstacle)

    for _ in range(12):  # Ajusta la cantidad de obstáculos según sea necesario
        shape = random.choice(shapes)
        color = BLACK

        # Generar posición en la cuadrícula
        row = random.randint(0, grid_rows - 1)
        col = random.randint(0, grid_cols - 1)

        position = (col * grid_size + grid_size // 2, row * grid_size + grid_size // 2)

        # Verificar si la nueva figura se superpone con alguna existente
        while any(obstacle.rect.colliderect(pygame.Rect(position, (50, 50))) for obstacle in obstacles):
            row = random.randint(0, grid_rows - 1)
            col = random.randint(0, grid_cols - 1)
            position = (col * grid_size + grid_size // 2, row * grid_size + grid_size // 2)

        obstacle = Obstacle(shape, color, position)
        obstacles.add(obstacle)

        origin_obstacle = Obstacle("origin_circle", (255, 0, 0), (WIDTH - 30, HEIGHT - 30))  # Ajusta la posición según sea necesario
        obstacles.add(origin_obstacle)

    return obstacles

# Función para realizar la búsqueda en amplitud
def bfs(obstacles, start, goal):
    bfs.visited_nodes = set()
    visited = set()
    queue = deque([(start, [])])

    while queue:
        for event in pygame.event.get():  # Captura eventos aquí
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

        current, path = queue.popleft()

        if current == goal:
            bfs.visited_nodes.add(current)
            return path

        if current not in visited:
            visited.add(current)
            bfs.visited_nodes.add(current)
            neighbors = get_valid_neighbors(obstacles, current)
            queue.extend((neighbor, path + [current]) for neighbor in neighbors)

    return None

# Función para obtener vecinos válidos de una posición
def get_valid_neighbors(obstacles, position):
    x, y = position
    possible_neighbors = [(x + 50, y), (x - 50, y), (x, y + 50), (x, y - 50)]
    valid_neighbors = [neighbor for neighbor in possible_neighbors if not any(obstacle.rect.collidepoint(neighbor) for obstacle in obstacles)]
    return valid_neighbors

# Función principal
def main():
    clock = pygame.time.Clock()

    obstacles = generate_obstacles()

    # Puntos de inicio y destino para BFS
    origin_position = (WIDTH - 30, HEIGHT - 30)
    destination_position = obstacles.sprites()[0].rect.center  # El destino es la posición de la "X"

    # Realizar la búsqueda en amplitud
    path = bfs(obstacles, origin_position, destination_position)

    current_index = 0
    circle_position = origin_position

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

        # Dibuja el fondo
        screen.fill(WHITE)

        # Dibuja los obstáculos
        obstacles.draw(screen)

        # Dibuja los nodos visitados durante la búsqueda en amplitud
        for node in bfs.visited_nodes:
            pygame.draw.circle(screen, (0, 255, 0), node, 10)

        # Dibuja el camino encontrado por BFS
        if path is not None:
            pygame.draw.lines(screen, (0, 0, 255), False, path, 5)

        # Mueve el círculo a lo largo del camino
        # Mueve el círculo a lo largo del camino
        if path is not None and current_index < len(path):
            circle_position = path[current_index]
            current_index += 1


        # **Actualización de la posición del círculo dentro del bucle while**
        pygame.draw.circle(screen, (0, 0, 255), circle_position, 15)

        # Impresiones para depuración
        for obstacle in obstacles:
            print("Obstacle Position:", obstacle.rect.center)
        print("Origin Position:", origin_position)
        print("Destination Position:", destination_position)
        print("Circle Position:", circle_position)

        if path is not None:
            print("Path Length:", len(path))
        else:
            print("No path found.")

        pygame.display.flip()
        clock.tick(2)  # Ajusta la velocidad de la animación según sea necesario

if __name__ == "__main__":
    main()
