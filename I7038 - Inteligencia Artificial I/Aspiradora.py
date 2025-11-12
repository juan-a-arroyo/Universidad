import pygame
import random

# Definir colores
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
GREY = (200, 200, 200)
RED = (255, 0, 0)

# Definir dimensiones de la pantalla y la cuadrícula
SCREEN_WIDTH = 600
SCREEN_HEIGHT = 600
CELL_SIZE = 60
GRID_WIDTH = SCREEN_WIDTH // CELL_SIZE
GRID_HEIGHT = SCREEN_HEIGHT // CELL_SIZE

# Definir la clase para la aspiradora
class Vacuum:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def draw(self, screen):
        pygame.draw.rect(screen, RED, (self.x * CELL_SIZE, self.y * CELL_SIZE, CELL_SIZE, CELL_SIZE))

    def move_random(self):
        direction = random.choice(["up", "down", "left", "right"])
        if direction == "up" and self.y > 0:
            self.y -= 1
        elif direction == "down" and self.y < GRID_HEIGHT - 1:
            self.y += 1
        elif direction == "left" and self.x > 0:
            self.x -= 1
        elif direction == "right" and self.x < GRID_WIDTH - 1:
            self.x += 1

# Definir la clase para el entorno
class Environment:
    def __init__(self):
        self.grid = [[random.choice([0, 1]) for _ in range(GRID_WIDTH)] for _ in range(GRID_HEIGHT)]

    def draw(self, screen):
        for y in range(GRID_HEIGHT):
            for x in range(GRID_WIDTH):
                color = WHITE if self.grid[y][x] == 0 else BLACK
                pygame.draw.rect(screen, color, (x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE))

# Funcion principal
def main():
    pygame.init()

    # Configurar pantalla
    screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
    pygame.display.set_caption("Simulador de Aspiradora")

    # Inicializar aspiradora y entorno
    vacuum = Vacuum(random.randint(0, GRID_WIDTH-1), random.randint(0, GRID_HEIGHT-1))
    environment = Environment()

    clock = pygame.time.Clock()
    running = True

    # Bucle principal del juego
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        # Movimiento de la aspiradora
        vacuum.move_random()

        # Logica de actualizacion y dibujo
        screen.fill(GREY)
        environment.draw(screen)
        vacuum.draw(screen)

        pygame.display.flip()
        clock.tick(6)  # Cambiar esto para controlar la velocidad de movimiento de la aspiradora

    pygame.quit()

if __name__ == "__main__":
    main()
