import pygame
import sys
import random

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
    def __init__(self, x, y, speed):
        self.x = x
        self.y = y
        self.speed = speed / 10
        self.best_x = x
        self.best_y = y

    def move(self):
        self.x += self.speed
        self.y += self.speed

    def evaluate(self, target_x, target_y):
        return abs(target_x - self.x) + abs(target_y - self.y)

def pso():
    particles = [Particle(random.randint(0, 19), random.randint(0, 19), random.randint(-1, 1)) for _ in range(10)]
    target_x = 1
    target_y = 0

    for _ in range(100):
        for particle in particles:
            fitness = particle.evaluate(target_x, target_y)
            if fitness < particle.evaluate(particle.best_x, particle.best_y):
                particle.best_x = particle.x
                particle.best_y = particle.y
            particle.move()

        global_best_x = min(particles, key=lambda p: p.evaluate(p.best_x, p.best_y)).best_x
        global_best_y = min(particles, key=lambda p: p.evaluate(p.best_x, p.best_y)).best_y

        for particle in particles:
            if random.random() < 0.5:
                particle.speed = particle.best_x - particle.x
            else:
                particle.speed = global_best_x - particle.x

            if random.random() < 0.5:
                particle.speed = particle.best_y - particle.y
            else:
                particle.speed = global_best_y - particle.y

    best_particle = min(particles, key=lambda p: p.evaluate(p.x, p.y))
    return best_particle.x, best_particle.y


def dibujar_laberinto(matriz, pantalla):
    for fila in range(len(matriz)):
        for col in range(len(matriz[fila])):
            if matriz[fila][col] == 0:
                pygame.draw.rect(pantalla, NEGRO, (col * TAMANO_CELDA, fila * TAMANO_CELDA, TAMANO_CELDA, TAMANO_CELDA))
            else:
                pygame.draw.rect(pantalla, BLANCO, (col * TAMANO_CELDA, fila * TAMANO_CELDA, TAMANO_CELDA, TAMANO_CELDA))
    
    # Dibujar cuadro rojo en (2, 1)
    pygame.draw.rect(pantalla, ROJO, (1 * TAMANO_CELDA, 0 * TAMANO_CELDA, TAMANO_CELDA, TAMANO_CELDA))
    
    # Dibujar cuadro azul en (19, 19)
    pygame.draw.rect(pantalla, AZUL, (19 * TAMANO_CELDA, 19 * TAMANO_CELDA, TAMANO_CELDA, TAMANO_CELDA))

def main():
    pygame.init()
    pantalla = pygame.display.set_mode((ANCHO, ALTO))
    pygame.display.set_caption("Laberinto")

    reloj = pygame.time.Clock()

    while True:
        for evento in pygame.event.get():
            if evento.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

        pantalla.fill(NEGRO)
        dibujar_laberinto(laberinto, pantalla)

        best_x, best_y = pso()
        pygame.draw.rect(pantalla, AZUL, (best_x * TAMANO_CELDA, best_y * TAMANO_CELDA, TAMANO_CELDA, TAMANO_CELDA))

        pygame.display.flip()
        pygame.time.delay(100)  # Agregar un retraso de 100 milisegundos

        reloj.tick(60)

if __name__ == "__main__":
    main()
