from MainWindow import MainWindow
from PySide2.QtWidgets import QApplication
import sys

# Aplicación de Qt
app = QApplication()
# Se crea un botón para la palabra Hola
window = MainWindow()
# Se hace visible el botón
window.show()
# Qt loop
sys.exit(app.exec_())
