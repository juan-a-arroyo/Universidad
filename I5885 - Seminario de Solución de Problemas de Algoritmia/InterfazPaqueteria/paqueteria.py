from paquete import Paquete

class Paqueteria:
    def __init__(self) -> None:
        self.paquetes = []


    def mostrarPaquetes(self):
        for e in self.paquetes:
            e.mostrar()

    def insertarFinal(self, paquete):
        self.paquetes.append(paquete)
    
    def insertarInicio(self,paquete):
        self.paquetes.insert(0,paquete)

    def __str__(self) -> str:
        # allP = ""
        # for p in self.paquetes:
        #     allP = allP + str(p) + "\n" 
        # return allP
        return "".join(str(paquete)+"\n" for paquete in self.paquetes)