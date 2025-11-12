class Paquete:
    
    def __init__(self,id="",origen="",destino="",peso=0.0):
        self.__id = id
        self._origen = origen
        self.destino = destino
        self.peso = peso

    # def mostrar(self):
    #     print("El paquete va de",self._origen, "a", self.destino)

    def __str__(self) -> str:
        return "Mi paquete "+ self.__id +" va de "+self._origen+ " a "+ self.destino+ " y pesa "+ str(self.peso) + " kg"