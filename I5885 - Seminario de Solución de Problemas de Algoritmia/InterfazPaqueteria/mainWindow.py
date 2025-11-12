from ui_mainwindow import Ui_MainWindow
from PySide2.QtWidgets import QMainWindow
from paquete import Paquete
from paqueteria import Paqueteria


class MainWindow(QMainWindow):
    def __init__(self):
        super(MainWindow,self).__init__()
        self.paqueteria = Paqueteria()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.ui.mandar_pushButton.clicked.connect(self.click_Mandar)
        self.ui.mandarPrioridad_pushButton.clicked.connect(self.click_MandarPrioridad)
        self.ui.mostrar_pushButton.clicked.connect(self.mostrarPaquetes)

    def click_Mandar(self):
        id = self.ui.id_lineEdit.text()
        origen = self.ui.origen_lineEdit.text()
        destino = self.ui.destino_lineEdit.text()
        peso = self.ui.peso_doubleSpinBox.value()

        self.paqueteria.insertarFinal(Paquete(id,origen,destino,peso))
        self.clearUI()

    def click_MandarPrioridad(self):
        id = self.ui.id_lineEdit.text()
        origen = self.ui.origen_lineEdit.text()
        destino = self.ui.destino_lineEdit.text()
        peso = self.ui.peso_doubleSpinBox.value()

        self.paqueteria.insertarInicio(Paquete(id,origen,destino,peso))
        self.clearUI()
    
    def mostrarPaquetes(self):
        self.ui.salida_plainTextEdit.clear()
        self.ui.salida_plainTextEdit.insertPlainText(str(self.paqueteria))

    def clearUI(self):
        self.ui.id_lineEdit.clear()
        self.ui.origen_lineEdit.clear()
        self.ui.destino_lineEdit.clear()
        self.ui.peso_doubleSpinBox.clear()
