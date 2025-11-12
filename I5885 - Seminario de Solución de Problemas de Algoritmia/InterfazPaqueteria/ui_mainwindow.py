# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'mainwindow.ui'
##
## Created by: Qt User Interface Compiler version 5.15.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(545, 359)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.gridLayout_2 = QGridLayout(self.centralwidget)
        self.gridLayout_2.setObjectName(u"gridLayout_2")
        self.groupBox = QGroupBox(self.centralwidget)
        self.groupBox.setObjectName(u"groupBox")
        self.gridLayout = QGridLayout(self.groupBox)
        self.gridLayout.setObjectName(u"gridLayout")
        self.mandar_pushButton = QPushButton(self.groupBox)
        self.mandar_pushButton.setObjectName(u"mandar_pushButton")

        self.gridLayout.addWidget(self.mandar_pushButton, 4, 0, 1, 2)

        self.label_2 = QLabel(self.groupBox)
        self.label_2.setObjectName(u"label_2")

        self.gridLayout.addWidget(self.label_2, 1, 0, 1, 1)

        self.peso_doubleSpinBox = QDoubleSpinBox(self.groupBox)
        self.peso_doubleSpinBox.setObjectName(u"peso_doubleSpinBox")
        self.peso_doubleSpinBox.setDecimals(3)
        self.peso_doubleSpinBox.setMaximum(1000.000000000000000)
        self.peso_doubleSpinBox.setSingleStep(0.500000000000000)

        self.gridLayout.addWidget(self.peso_doubleSpinBox, 3, 1, 1, 1)

        self.label_3 = QLabel(self.groupBox)
        self.label_3.setObjectName(u"label_3")

        self.gridLayout.addWidget(self.label_3, 2, 0, 1, 1)

        self.id_lineEdit = QLineEdit(self.groupBox)
        self.id_lineEdit.setObjectName(u"id_lineEdit")

        self.gridLayout.addWidget(self.id_lineEdit, 0, 1, 1, 1)

        self.label = QLabel(self.groupBox)
        self.label.setObjectName(u"label")

        self.gridLayout.addWidget(self.label, 0, 0, 1, 1)

        self.label_4 = QLabel(self.groupBox)
        self.label_4.setObjectName(u"label_4")

        self.gridLayout.addWidget(self.label_4, 3, 0, 1, 1)

        self.destino_lineEdit = QLineEdit(self.groupBox)
        self.destino_lineEdit.setObjectName(u"destino_lineEdit")

        self.gridLayout.addWidget(self.destino_lineEdit, 2, 1, 1, 1)

        self.origen_lineEdit = QLineEdit(self.groupBox)
        self.origen_lineEdit.setObjectName(u"origen_lineEdit")

        self.gridLayout.addWidget(self.origen_lineEdit, 1, 1, 1, 1)

        self.mandarPrioridad_pushButton = QPushButton(self.groupBox)
        self.mandarPrioridad_pushButton.setObjectName(u"mandarPrioridad_pushButton")

        self.gridLayout.addWidget(self.mandarPrioridad_pushButton, 5, 0, 1, 2)

        self.mostrar_pushButton = QPushButton(self.groupBox)
        self.mostrar_pushButton.setObjectName(u"mostrar_pushButton")

        self.gridLayout.addWidget(self.mostrar_pushButton, 6, 0, 1, 2)


        self.gridLayout_2.addWidget(self.groupBox, 0, 0, 1, 1)

        self.salida_plainTextEdit = QPlainTextEdit(self.centralwidget)
        self.salida_plainTextEdit.setObjectName(u"salida_plainTextEdit")

        self.gridLayout_2.addWidget(self.salida_plainTextEdit, 0, 1, 1, 1)

        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 545, 21))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.groupBox.setTitle(QCoreApplication.translate("MainWindow", u"Paquete", None))
        self.mandar_pushButton.setText(QCoreApplication.translate("MainWindow", u"Mandar", None))
        self.label_2.setText(QCoreApplication.translate("MainWindow", u"Origen:", None))
        self.label_3.setText(QCoreApplication.translate("MainWindow", u"Destino:", None))
        self.label.setText(QCoreApplication.translate("MainWindow", u"Id:", None))
        self.label_4.setText(QCoreApplication.translate("MainWindow", u"Peso:", None))
        self.mandarPrioridad_pushButton.setText(QCoreApplication.translate("MainWindow", u"Mandar con Prioridad", None))
        self.mostrar_pushButton.setText(QCoreApplication.translate("MainWindow", u"Mostrar", None))
    # retranslateUi

