import pygame
import sys
import random
import numpy as np

# Definir colores
NEGRO = (0, 0, 0)
BLANCO = (255, 255, 255)
ROJO = (255, 0, 0)
AZUL = (0, 0, 255)

# Definir el tamaño de la ventana y el tamaño de cada celda del laberinto
ANCHO = 600
ALTO = 600
TAMANO_CELDA = 29

# Matriz del laberinto (ejemplo)
laberinto = [
    [0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1],
    [0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1],
    [0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1],
    [0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1],
    [0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1],
    [0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1],
    [0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1],
    [0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1],
    [0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1],
    [0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1],
    [0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1],
    [0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1],
    [0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1],
    [0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1],
    [0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1],
    [0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0]
]

class Particle:
    def __init__(self):
        self.position = self.initialize_position()
        self.velocity = [0, 0]
        self.best_position = self.position.copy()
        self.best_fitness = float('inf')

    def initialize_position(self):
        # Initialize position randomly until a valid position is found
        while True:
            position = [random.randint(0, len(laberinto[0]) - 1), random.randint(0, len(laberinto) - 1)]
            if laberinto[position[1]][position[0]] == 1:
                return position

    def update_velocity(self, global_best_position):
        w = 0.5
        c1 = 1
        c2 = 2
        for i in range(2):
            r1 = random.random()
            r2 = random.random()
            self.velocity[i] = w * self.velocity[i] + c1 * r1 * (self.best_position[i] - self.position[i]) + \
                               c2 * r2 * (global_best_position[i] - self.position[i])

    def update_position(self):
        for i in range(2):
            self.position[i] += int(round(self.velocity[i]))

            # Ensure particle stays within the bounds of the maze
            self.position[i] = max(0, min(self.position[i], len(laberinto[0]) - 1))

    def evaluate_fitness(self):
        # Euclidean distance to the blue square
        distance = np.linalg.norm([self.position[0] - 19, self.position[1] - 19])

        # Penalize if the position is a black cell
        if laberinto[self.position[1]][self.position[0]] == 0:
            distance += 1000

        return distance

def main():
    pygame.init()
    pantalla = pygame.display.set_mode((ANCHO, ALTO))
    pygame.display.set_caption("Laberinto")

    reloj = pygame.time.Clock()

    num_particles = 10
    particles = [Particle() for _ in range(num_particles)]
    global_best_position = [particle.position.copy() for particle in particles]
    global_best_fitness = float('inf')

    while True:
        for evento in pygame.event.get():
            if evento.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

        pantalla.fill(NEGRO)
        for particle in particles:
            pygame.draw.circle(pantalla, BLANCO, (particle.position[0] * TAMANO_CELDA + TAMANO_CELDA // 2,
                                                   particle.position[1] * TAMANO_CELDA + TAMANO_CELDA // 2), 5)

            fitness = particle.evaluate_fitness()
            if fitness < particle.best_fitness:
                particle.best_fitness = fitness
                particle.best_position = particle.position.copy()

            if fitness < global_best_fitness:
                global_best_fitness = fitness
                global_best_position = particle.position.copy()

            particle.update_velocity(global_best_position)
            particle.update_position()

        pygame.draw.rect(pantalla, ROJO, (1 * TAMANO_CELDA, 0 * TAMANO_CELDA, TAMANO_CELDA, TAMANO_CELDA))
        pygame.draw.rect(pantalla, AZUL, (19 * TAMANO_CELDA, 19 * TAMANO_CELDA, TAMANO_CELDA, TAMANO_CELDA))

        pygame.display.flip()
        reloj.tick(60)

if __name__ == "__main__":
    main()

