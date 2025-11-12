from UI_MainWindow import Ui_MainWindow
from PySide2.QtWidgets import QFileDialog, QMainWindow, QMessageBox
from Partícula import Particula
from Partículas import Particulas

class MainWindow(QMainWindow):
    def __init__(self):
        super(MainWindow,self).__init__()
        self.Particle = Particulas()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.ui.inicio_pushButton.clicked.connect(self.ClickInicio)
        self.ui.final_pushButton.clicked.connect(self.ClickFinal)
        self.ui.mostrar_pushButton.clicked.connect(self.Mostrar)
        self.ui.actionAbrir.triggered.connect(self.Abrir)
        self.ui.actionGuardar.triggered.connect(self.Guardar)

    def Guardar(self):
        ubicacion = QFileDialog.getSaveFileName(self,'Guardar Partículas', '.', 'JSON (*.json)')
        print(ubicacion[0])
        try:
            self.Particle.guardar(ubicacion[0])
            QMessageBox.information(self,"Exito","Se guardó correctamente en "+ubicacion[0])
        except:
            QMessageBox.critical(self,"Error","No se pudo guardar el archivo")


    def Abrir(self):
        ubicacion = QFileDialog.getOpenFileName(self, 'Abrir Partículas', '.', 'JSON (*.json)')[0]
        try:
            self.Particle.abrir(ubicacion)
            QMessageBox.information(self,"Exito","Se abrió correctamente en "+ubicacion)
        except:
            QMessageBox.critical(self,"Error","No se pudo abrir el archivo")
    
    def ClickInicio(self):
        id = self.ui.id_lineEdit.text()
        origen_x = self.ui.ox_doubleSpinBox.value()
        origen_y = self.ui.oy_doubleSpinBox.value()
        destino_x = self.ui.dx_doubleSpinBox.value()
        destino_y = self.ui.dy_doubleSpinBox.value()
        velocidad = self.ui.vel_lineEdit.text()
        red = self.ui.r_doubleSpinBox.value()
        green = self.ui.g_doubleSpinBox.value()
        blue = self.ui.b_doubleSpinBox.value()

        self.Particle.agregar_inicio(Particula(id,origen_x,origen_y,destino_x,destino_y,velocidad,red,green,blue))

    def ClickFinal(self):
        id = self.ui.id_lineEdit.text()
        origen_x = self.ui.ox_doubleSpinBox.value()
        origen_y = self.ui.oy_doubleSpinBox.value()
        destino_x = self.ui.dx_doubleSpinBox.value()
        destino_y = self.ui.dy_doubleSpinBox.value()
        velocidad = self.ui.vel_lineEdit.text()
        red = self.ui.r_doubleSpinBox.value()
        green = self.ui.g_doubleSpinBox.value()
        blue = self.ui.b_doubleSpinBox.value()

        self.Particle.agregar_final(Particula(id,origen_x,origen_y,destino_x,destino_y,velocidad,red,green,blue))

    def Mostrar(self):
        self.ui.plainTextEdit.clear()
        self.ui.plainTextEdit.insertPlainText(str(self.Particle))