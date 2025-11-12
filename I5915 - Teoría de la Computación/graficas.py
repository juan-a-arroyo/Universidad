import matplotlib.pyplot as plt
years = [2000, 2005, 2010, 2015, 2020]
population = [6_000_000, 6_500_000, 7_000_000, 7_500_000, 8_000_000]
plt.plot(years, population)
plt.xlabel('Años')
plt.ylabel('Población')
plt.title('Densidad de Población')
plt.show()
