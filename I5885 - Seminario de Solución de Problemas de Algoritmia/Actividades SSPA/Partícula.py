from algoritmos import distancia_euclidiana

class Particula:
    def __init__(self,id,origen_x,origen_y,destino_x,destino_y,velocidad,red,green,blue):
        self.id = id
        self.origen_x = origen_x
        self.origen_y = origen_y
        self.destino_x = destino_x
        self.destino_y = destino_y
        self.velocidad = velocidad
        self.red = red
        self.green = green
        self.blue = blue
        self.distancia = distancia_euclidiana(origen_x,origen_y,destino_x,destino_y)
    
    def imprimir(self):
        print("Mi partícula va de X:",self.origen_x,"Y:",self.origen_y,"a X:",self.destino_x,"Y:",self.destino_y)

    def __str__(self) -> str:
        return "Mi partícula "+str(self.id)+" va de X:"+str(self.origen_x)+" Y:"+str(self.origen_y)+" a X:"+str(self.destino_x)+" Y:"+str(self.destino_y)+" a una velocidad de: "+str(self.velocidad)+" con los colores R:"+str(self.red)+", G:"+str(self.green)+", B:"+str(self.blue)+" y su distancia es de: "+str(self.distancia)

    def to_json(self):
        return{
            "id": self.id,
            "origen_x": self.origen_x,
            "origen_y": self.origen_y,
            "destino_x": self.destino_x,
            "destino_y": self.destino_y,
            "velocidad": self.velocidad,
            "red": self.red,
            "green": self.green,
            "blue": self.blue
        }