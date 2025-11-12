from heapq import heappop, heappush

class MazeSolverAStar:
    def __init__(self, maze, start, goal):
        self.maze = maze
        self.start = start
        self.goal = goal
        self.rows = len(maze)
        self.cols = len(maze[0])
        self.directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    def heuristic(self, cell):
        # Heurística: Distancia de Manhattan
        return abs(cell[0] - self.goal[0]) + abs(cell[1] - self.goal[1])

    def is_valid_move(self, row, col):
        return 0 <= row < self.rows and 0 <= col < self.cols and self.maze[row][col] == 1

    def solve_maze(self):
        frontier = [(self.heuristic(self.start), 0, self.start)]  # (heurística, costo acumulado, celda)
        came_from = {}
        cost_so_far = {self.start: 0}

        while frontier:
            _, current_cost, current_cell = heappop(frontier)

            if current_cell == self.goal:
                return self.reconstruct_path(came_from, current_cell)

            for dr, dc in self.directions:
                new_row, new_col = current_cell[0] + dr, current_cell[1] + dc
                new_cost = current_cost + 1

                if self.is_valid_move(new_row, new_col):
                    new_cell = (new_row, new_col)
                    if new_cell not in cost_so_far or new_cost < cost_so_far[new_cell]:
                        cost_so_far[new_cell] = new_cost
                        priority = new_cost + self.heuristic(new_cell)
                        heappush(frontier, (priority, new_cost, new_cell))
                        came_from[new_cell] = current_cell

        return None  # No se encontró una solución

    def reconstruct_path(self, came_from, current_cell):
        path = []
        while current_cell in came_from:
            path.append(current_cell)
            current_cell = came_from[current_cell]
        path.append(self.start)
        path.reverse()
        return path

def print_maze_with_path(maze, path):
    for i, row in enumerate(maze):
        for j, cell in enumerate(row):
            if (i, j) in path:
                print("O", end="")
            elif cell == 1:
                print(".", end="")
            elif cell == 0:
                print("#", end="")
        print()

if __name__ == "__main__":
    maze = [
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        [1, 0, 0, 0, 0, 0, 1, 0, 0, 1],
        [1, 0, 1, 1, 1, 0, 1, 0, 1, 1],
        [1, 0, 1, 0, 0, 0, 1, 0, 0, 1],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    ]
    start = (0, 0)
    goal = (4, 9)

    maze_solver = MazeSolverAStar(maze, start, goal)
    path = maze_solver.solve_maze()

    if path:
        print("Solución encontrada:")
        print_maze_with_path(maze, path)
    else:
        print("No se encontró una solución.")
