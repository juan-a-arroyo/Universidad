import numpy as np
import matplotlib.pyplot as plt

class HarmonySearch:
    def __init__(self, objective_function, num_variables, num_harmonies, improv_rate=0.1, pitch_adjust_rate=0.01,
                 bandwidth=0.01, max_iter=1000, tol=1e-6):
        self.objective_function = objective_function
        self.num_variables = num_variables
        self.num_harmonies = num_harmonies
        self.improv_rate = improv_rate
        self.pitch_adjust_rate = pitch_adjust_rate
        self.bandwidth = bandwidth
        self.max_iter = max_iter
        self.tol = tol

    def initialize_harmonies(self):
        harmonies = np.random.rand(self.num_harmonies, self.num_variables)
        return harmonies

    def improvise(self, harmonies):
        new_harmonies = np.zeros_like(harmonies)
        for i in range(self.num_harmonies):
            for j in range(self.num_variables):
                if np.random.rand() < self.improv_rate:
                    new_harmonies[i, j] = np.random.rand()
                else:
                    new_harmonies[i, j] = harmonies[np.random.randint(self.num_harmonies), j]
        return new_harmonies

    def adjust_pitch(self, harmonies):
        new_harmonies = np.zeros_like(harmonies)
        for i in range(self.num_harmonies):
            for j in range(self.num_variables):
                if np.random.rand() < self.pitch_adjust_rate:
                    adjustment = self.bandwidth * np.random.randn()
                    new_value = harmonies[i, j] + adjustment
                    new_value = min(max(new_value, 0), 1)  # Ensure values are within bounds
                    new_harmonies[i, j] = new_value
                else:
                    new_harmonies[i, j] = harmonies[i, j]
        return new_harmonies

    def search(self):
        harmonies = self.initialize_harmonies()
        best_solution = None
        best_fitness = np.inf
        iteration = 0
        fitness_history = []

        while iteration < self.max_iter:
            improvised_harmonies = self.improvise(harmonies)
            adjusted_harmonies = self.adjust_pitch(improvised_harmonies)

            # Evaluate objective function
            fitness_values = np.apply_along_axis(self.objective_function, 1, adjusted_harmonies)

            # Update best solution
            min_fitness = np.min(fitness_values)
            min_index = np.argmin(fitness_values)
            if min_fitness < best_fitness:
                best_solution = adjusted_harmonies[min_index]
                best_fitness = min_fitness

            fitness_history.append(best_fitness)

            if abs(best_fitness) < self.tol:
                break

            iteration += 1

        return best_solution, best_fitness, fitness_history

# Example usage:
if __name__ == "__main__":
    # Define the objective function
    def sphere_function(x):
        return np.sum(x ** 2)

    # Initialize Harmony Search
    num_variables = 5
    num_harmonies = 20
    hs = HarmonySearch(objective_function=sphere_function,
                       num_variables=num_variables,
                       num_harmonies=num_harmonies)

    # Run Harmony Search algorithm
    best_solution, best_fitness, fitness_history = hs.search()

    # Plot fitness history
    plt.figure()
    plt.plot(fitness_history)
    plt.title("Convergence of Harmony Search")
    plt.xlabel("Iteration")
    plt.ylabel("Best Fitness")
    plt.show()

    print("Best solution:", best_solution)
    print("Best fitness:", best_fitness)
