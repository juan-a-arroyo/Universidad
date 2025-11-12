import pygame
import random

# Definir colores
WHITE = (255, 255, 255)
RED = (255, 0, 0)
BLACK = (0, 0, 0)

# Definir dimensiones del mundo
GRID_SIZE = 10
CELL_SIZE = 50
WINDOW_SIZE = GRID_SIZE * CELL_SIZE

# Clase del entorno de la aspiradora
class Environment:
    def __init__(self):
        self.grid = [[random.choice([0, 1]) for _ in range(GRID_SIZE)] for _ in range(GRID_SIZE)]
        self.agent_pos = (0, 0)
        self.score = 0

    def draw(self, screen):
        for y in range(GRID_SIZE):
            for x in range(GRID_SIZE):
                color = WHITE if self.grid[y][x] == 0 else BLACK
                pygame.draw.rect(screen, color, (x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE))
        pygame.draw.rect(screen, RED, (self.agent_pos[0] * CELL_SIZE, self.agent_pos[1] * CELL_SIZE, CELL_SIZE, CELL_SIZE))

    def move_agent(self, new_pos):
        self.agent_pos = new_pos
        self.score -= 1  # Penalizar cada movimiento

    def clean(self):
        x, y = self.agent_pos
        if self.grid[y][x] == 1:
            self.grid[y][x] = 0
            self.score += 10  # Recompensar por limpiar

    def get_perception(self):
        return self.agent_pos, self.grid[self.agent_pos[1]][self.agent_pos[0]]

    def all_clean(self):
        for row in self.grid:
            if 1 in row:
                return False
        return True


# Clase del agente reactivo simple
class SimpleReflexAgent:
    def __init__(self):
        self.visited = set()

    def decide_action(self, perception):
        pos, dirt = perception
        self.visited.add(pos)

        if dirt == 1:
            return "CLEAN"
        elif self.any_dirty_position():
            return self.closest_dirty_position(pos)
        else:
            return self.random_move(pos)

    def any_dirty_position(self):
        global env
        return True in [True in row for row in env.grid]

    def closest_dirty_position(self, current_pos):
        dirty_positions = [(x, y) for y, row in enumerate(env.grid) for x, cell in enumerate(row) if cell == 1]
        distances = [abs(pos[0] - current_pos[0]) + abs(pos[1] - current_pos[1]) for pos in dirty_positions]
        closest_index = distances.index(min(distances))
        closest_pos = dirty_positions[closest_index]

        if closest_pos[0] < current_pos[0]:
            return "LEFT"
        elif closest_pos[0] > current_pos[0]:
            return "RIGHT"
        elif closest_pos[1] < current_pos[1]:
            return "UP"
        else:
            return "DOWN"

    def random_move(self, current_pos):
        possible_moves = []
        if current_pos[0] > 0 and (current_pos[0] - 1, current_pos[1]) not in self.visited:
            possible_moves.append("LEFT")
        if current_pos[0] < GRID_SIZE - 1 and (current_pos[0] + 1, current_pos[1]) not in self.visited:
            possible_moves.append("RIGHT")
        if current_pos[1] > 0 and (current_pos[0], current_pos[1] - 1) not in self.visited:
            possible_moves.append("UP")
        if current_pos[1] < GRID_SIZE - 1 and (current_pos[0], current_pos[1] + 1) not in self.visited:
            possible_moves.append("DOWN")

        return random.choice(possible_moves) if possible_moves else None


# Función principal para el simulador
def main():
    pygame.init()
    screen = pygame.display.set_mode((WINDOW_SIZE, WINDOW_SIZE))
    pygame.display.set_caption("Simulador de aspiradora")

    global env
    env = Environment()
    agent = SimpleReflexAgent()

    running = True
    clock = pygame.time.Clock()

    while running:
        screen.fill(WHITE)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        agent_action = agent.decide_action(env.get_perception())
        if agent_action == "CLEAN":
            env.clean()
        else:
            new_pos = env.agent_pos
            if agent_action == "UP":
                new_pos = (env.agent_pos[0], max(env.agent_pos[1] - 1, 0))
            elif agent_action == "DOWN":
                new_pos = (env.agent_pos[0], min(env.agent_pos[1] + 1, GRID_SIZE - 1))
            elif agent_action == "LEFT":
                new_pos = (max(env.agent_pos[0] - 1, 0), env.agent_pos[1])
            elif agent_action == "RIGHT":
                new_pos = (min(env.agent_pos[0] + 1, GRID_SIZE - 1), env.agent_pos[1])

            env.move_agent(new_pos)

        if env.all_clean():
            env.grid = [[random.choice([0, 1]) for _ in range(GRID_SIZE)] for _ in range(GRID_SIZE)]
            agent.visited.clear()

        env.draw(screen)
        pygame.display.flip()
        clock.tick(10)  # Controlar la velocidad de la simulación

    pygame.quit()

if __name__ == "__main__":
    main()
