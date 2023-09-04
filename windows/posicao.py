# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Posicao.ui'
#
# Created by: PyQt5 UI code generator 5.9.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1200, 840)
        font = QtGui.QFont()
        font.setPointSize(8)
        MainWindow.setFont(font)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.Simular = QtWidgets.QPushButton(self.centralwidget)
        self.Simular.setGeometry(QtCore.QRect(10, 490, 121, 41))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.Simular.setFont(font)
        self.Simular.setObjectName("Simular")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(10, 330, 47, 13))
        self.label.setObjectName("label")
        self.InfoAtual = QtWidgets.QLabel(self.centralwidget)
        self.InfoAtual.setGeometry(QtCore.QRect(150, 370, 291, 16))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.InfoAtual.setFont(font)
        self.InfoAtual.setObjectName("InfoAtual")
        self.GraficoAnterior = PlotWidget(self.centralwidget)
        self.GraficoAnterior.setGeometry(QtCore.QRect(150, 400, 1041, 341))
        self.GraficoAnterior.setObjectName("GraficoAnterior")
        self.Setpoint = QtWidgets.QSpinBox(self.centralwidget)
        self.Setpoint.setGeometry(QtCore.QRect(70, 330, 61, 22))
        self.Setpoint.setMinimum(0)
        self.Setpoint.setMaximum(359)
        self.Setpoint.setObjectName("Setpoint")
        self.Voltar = QtWidgets.QPushButton(self.centralwidget)
        self.Voltar.setGeometry(QtCore.QRect(10, 240, 121, 41))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.Voltar.setFont(font)
        self.Voltar.setObjectName("Voltar")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(10, 360, 47, 13))
        self.label_2.setObjectName("label_2")
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(10, 420, 47, 13))
        self.label_4.setObjectName("label_4")
        self.InfoAnterior = QtWidgets.QLabel(self.centralwidget)
        self.InfoAnterior.setGeometry(QtCore.QRect(150, 760, 291, 16))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.InfoAnterior.setFont(font)
        self.InfoAnterior.setObjectName("InfoAnterior")
        self.label_5 = QtWidgets.QLabel(self.centralwidget)
        self.label_5.setGeometry(QtCore.QRect(10, 200, 121, 31))
        font = QtGui.QFont()
        font.setPointSize(18)
        self.label_5.setFont(font)
        self.label_5.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.label_5.setLineWidth(1)
        self.label_5.setAlignment(QtCore.Qt.AlignCenter)
        self.label_5.setObjectName("label_5")
        self.Kp = QtWidgets.QDoubleSpinBox(self.centralwidget)
        self.Kp.setGeometry(QtCore.QRect(70, 360, 62, 22))
        self.Kp.setDecimals(3)
        self.Kp.setSingleStep(0.001)
        self.Kp.setObjectName("Kp")
        self.GraficoAtual = PlotWidget(self.centralwidget)
        self.GraficoAtual.setGeometry(QtCore.QRect(150, 10, 1041, 341))
        self.GraficoAtual.setObjectName("GraficoAtual")
        self.Ki = QtWidgets.QDoubleSpinBox(self.centralwidget)
        self.Ki.setGeometry(QtCore.QRect(70, 390, 62, 22))
        self.Ki.setDecimals(3)
        self.Ki.setSingleStep(0.001)
        self.Ki.setObjectName("Ki")
        self.Kd = QtWidgets.QDoubleSpinBox(self.centralwidget)
        self.Kd.setGeometry(QtCore.QRect(70, 420, 61, 22))
        self.Kd.setDecimals(3)
        self.Kd.setSingleStep(0.001)
        self.Kd.setObjectName("Kd")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(10, 390, 47, 13))
        self.label_3.setObjectName("label_3")
        self.line = QtWidgets.QFrame(self.centralwidget)
        self.line.setGeometry(QtCore.QRect(130, 0, 16, 801))
        self.line.setFrameShadow(QtWidgets.QFrame.Plain)
        self.line.setLineWidth(1)
        self.line.setFrameShape(QtWidgets.QFrame.VLine)
        self.line.setObjectName("line")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1200, 19))
        self.menubar.setObjectName("menubar")
        self.menuArquivo = QtWidgets.QMenu(self.menubar)
        self.menuArquivo.setObjectName("menuArquivo")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.statusbar.setFont(font)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.actionAbrir = QtWidgets.QAction(MainWindow)
        self.actionAbrir.setObjectName("actionAbrir")
        self.actionSalvar = QtWidgets.QAction(MainWindow)
        self.actionSalvar.setObjectName("actionSalvar")
        self.menuArquivo.addAction(self.actionAbrir)
        self.menuArquivo.addAction(self.actionSalvar)
        self.menubar.addAction(self.menuArquivo.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.Simular.setText(_translate("MainWindow", "Simular"))
        self.label.setText(_translate("MainWindow", "Setpoint:"))
        self.InfoAtual.setText(_translate("MainWindow", "TextLabel"))
        self.Voltar.setText(_translate("MainWindow", "Voltar"))
        self.label_2.setText(_translate("MainWindow", "Kp:"))
        self.label_4.setText(_translate("MainWindow", "Kd:"))
        self.InfoAnterior.setText(_translate("MainWindow", "TextLabel"))
        self.label_5.setText(_translate("MainWindow", "Posição"))
        self.label_3.setText(_translate("MainWindow", "Ki:"))
        self.menuArquivo.setTitle(_translate("MainWindow", "Arquivo"))
        self.actionAbrir.setText(_translate("MainWindow", "Abrir"))
        self.actionAbrir.setShortcut(_translate("MainWindow", "Ctrl+O"))
        self.actionSalvar.setText(_translate("MainWindow", "Salvar"))
        self.actionSalvar.setShortcut(_translate("MainWindow", "Ctrl+S"))

from pyqtgraph import PlotWidget

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

