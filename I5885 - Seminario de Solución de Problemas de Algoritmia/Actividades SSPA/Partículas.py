from Partícula import Particula
import json

class Particulas:
    def __init__(self):
        self.particulas = []

    def agregar_inicio(self,particula:Particula):
        self.particulas.insert(0,particula)

    def agregar_final(self,particula:Particula):
        self.particulas.append(particula)

    def mostrar(self):
        for e in self.particulas:
            e.imprimir()

    def __str__(self) -> str:
        #strAll = ""
        #for part in self.particulas:
        #    strAll += str(part) + "\n"
        #return strAll
        return "".join(str(part)+"\n" for part in self.particulas)

    def guardar(self,ubicacion):
        archivo = open(ubicacion, 'w')
        #archivo.write(str(self))
        listaDicc = [part.to_json() for part in self.particulas]
        json.dump(listaDicc,archivo,indent=5)

    def abrir(self,ubicacion):
        archivo = open(ubicacion,'r')
        listaDicc = json.load(archivo)
        self.particulas = [Particula(**dic) for dic in listaDicc]