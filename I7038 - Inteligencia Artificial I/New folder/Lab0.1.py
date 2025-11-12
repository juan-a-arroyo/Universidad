import pygame
import sys
from collections import deque

# Definir colores
NEGRO = (0, 0, 0)
BLANCO = (255, 255, 255)
ROJO = (255, 0, 0)
AZUL = (0, 0, 0)  # Cambiado a negro

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

def dibujar_laberinto(matriz, pantalla):
    for fila in range(len(matriz)):
        for col in range(len(matriz[fila])):
            if matriz[fila][col] == 0:
                pygame.draw.rect(pantalla, NEGRO, (col * TAMANO_CELDA, fila * TAMANO_CELDA, TAMANO_CELDA, TAMANO_CELDA))
            else:
                pygame.draw.rect(pantalla, BLANCO, (col * TAMANO_CELDA, fila * TAMANO_CELDA, TAMANO_CELDA, TAMANO_CELDA))
    
    # Dibujar cuadro rojo en (2, 1)
    pygame.draw.rect(pantalla, ROJO, (1 * TAMANO_CELDA, 0 * TAMANO_CELDA, TAMANO_CELDA, TAMANO_CELDA))

class LaberintoSolver:
    def __init__(self, laberinto):
        self.laberinto = laberinto
        self.visitado = set()
        self.camino = []

    def resolver_laberinto(self, pantalla):
        inicio = (1, 0)
        self._dfs(inicio)

        for paso in self.camino:
            pygame.draw.rect(pantalla, NEGRO, (paso[1] * TAMANO_CELDA, paso[0] * TAMANO_CELDA, TAMANO_CELDA, TAMANO_CELDA))  # Cambiado a negro
            pygame.display.flip()
            pygame.time.wait(100)

    def _dfs(self, posicion):
        self.visitado.add(posicion)
        self.camino.append(posicion)

        if posicion[0] == 19 and posicion[1] == 19:
            return True

        movimientos = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        for movimiento in movimientos:
            nueva_posicion = (posicion[0] + movimiento[0], posicion[1] + movimiento[1])

            if (
                0 <= nueva_posicion[0] < len(self.laberinto) and
                0 <= nueva_posicion[1] < len(self.laberinto[0]) and
                nueva_posicion not in self.visitado and
                self.laberinto[nueva_posicion[0]][nueva_posicion[1]] == 0
            ):
                if self._dfs(nueva_posicion):
                    return True

        self.camino.pop()
        return False

def main():
    pygame.init()
    pantalla = pygame.display.set_mode((ANCHO, ALTO))
    pygame.display.set_caption("Laberinto")

    reloj = pygame.time.Clock()

    laberinto_solver = LaberintoSolver(laberinto)

    while True:
        for evento in pygame.event.get():
            if evento.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

        pantalla.fill(NEGRO)
        dibujar_laberinto(laberinto, pantalla)
        laberinto_solver.resolver_laberinto(pantalla)

        pygame.display.flip()
        reloj.tick(60)

if __name__ == "__main__":
    main()
