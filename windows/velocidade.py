# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Velocidade.ui'
#
# Created by: PyQt5 UI code generator 5.9.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1366, 768)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.Kp = QtWidgets.QDoubleSpinBox(self.centralwidget)
        self.Kp.setGeometry(QtCore.QRect(70, 350, 62, 22))
        self.Kp.setDecimals(3)
        self.Kp.setSingleStep(1.0)
        self.Kp.setObjectName("Kp")
        self.Simular = QtWidgets.QPushButton(self.centralwidget)
        self.Simular.setGeometry(QtCore.QRect(10, 480, 121, 41))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.Simular.setFont(font)
        self.Simular.setObjectName("Simular")
        self.GraficoAnterior = PlotWidget(self.centralwidget)
        self.GraficoAnterior.setGeometry(QtCore.QRect(150, 360, 1201, 311))
        self.GraficoAnterior.setObjectName("GraficoAnterior")
        self.Ki = QtWidgets.QDoubleSpinBox(self.centralwidget)
        self.Ki.setGeometry(QtCore.QRect(70, 380, 62, 22))
        self.Ki.setDecimals(3)
        self.Ki.setSingleStep(1.0)
        self.Ki.setObjectName("Ki")
        self.Voltar = QtWidgets.QPushButton(self.centralwidget)
        self.Voltar.setGeometry(QtCore.QRect(10, 230, 121, 41))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.Voltar.setFont(font)
        self.Voltar.setObjectName("Voltar")
        self.InfoAtual = QtWidgets.QLabel(self.centralwidget)
        self.InfoAtual.setGeometry(QtCore.QRect(150, 330, 291, 16))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.InfoAtual.setFont(font)
        self.InfoAtual.setObjectName("InfoAtual")
        self.InfoAnterior = QtWidgets.QLabel(self.centralwidget)
        self.InfoAnterior.setGeometry(QtCore.QRect(150, 680, 291, 16))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.InfoAnterior.setFont(font)
        self.InfoAnterior.setObjectName("InfoAnterior")
        self.GraficoAtual = PlotWidget(self.centralwidget)
        self.GraficoAtual.setGeometry(QtCore.QRect(150, 10, 1201, 311))
        self.GraficoAtual.setObjectName("GraficoAtual")
        self.Kd = QtWidgets.QDoubleSpinBox(self.centralwidget)
        self.Kd.setGeometry(QtCore.QRect(70, 410, 61, 22))
        self.Kd.setDecimals(3)
        self.Kd.setSingleStep(1.0)
        self.Kd.setProperty("value", 0.0)
        self.Kd.setObjectName("Kd")
        self.line = QtWidgets.QFrame(self.centralwidget)
        self.line.setGeometry(QtCore.QRect(130, 0, 16, 801))
        self.line.setFrameShadow(QtWidgets.QFrame.Plain)
        self.line.setLineWidth(1)
        self.line.setFrameShape(QtWidgets.QFrame.VLine)
        self.line.setObjectName("line")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(10, 320, 47, 13))
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(10, 350, 47, 13))
        self.label_2.setObjectName("label_2")
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(10, 410, 47, 13))
        self.label_4.setObjectName("label_4")
        self.Setpoint = QtWidgets.QSpinBox(self.centralwidget)
        self.Setpoint.setGeometry(QtCore.QRect(70, 320, 61, 22))
        self.Setpoint.setMinimum(-700)
        self.Setpoint.setMaximum(700)
        self.Setpoint.setObjectName("Setpoint")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(10, 380, 47, 13))
        self.label_3.setObjectName("label_3")
        self.label_6 = QtWidgets.QLabel(self.centralwidget)
        self.label_6.setGeometry(QtCore.QRect(10, 190, 121, 31))
        font = QtGui.QFont()
        font.setPointSize(18)
        self.label_6.setFont(font)
        self.label_6.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.label_6.setLineWidth(1)
        self.label_6.setAlignment(QtCore.Qt.AlignCenter)
        self.label_6.setObjectName("label_6")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1366, 21))
        self.menubar.setObjectName("menubar")
        self.menuFile = QtWidgets.QMenu(self.menubar)
        self.menuFile.setObjectName("menuFile")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.statusbar.setFont(font)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.actionOpen = QtWidgets.QAction(MainWindow)
        self.actionOpen.setShortcutContext(QtCore.Qt.WindowShortcut)
        self.actionOpen.setObjectName("actionOpen")
        self.actionSave = QtWidgets.QAction(MainWindow)
        self.actionSave.setObjectName("actionSave")
        self.menuFile.addAction(self.actionOpen)
        self.menuFile.addAction(self.actionSave)
        self.menubar.addAction(self.menuFile.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Velocidade"))
        self.Simular.setText(_translate("MainWindow", "Simular"))
        self.Voltar.setText(_translate("MainWindow", "Voltar"))
        self.InfoAtual.setText(_translate("MainWindow", "TextLabel"))
        self.InfoAnterior.setText(_translate("MainWindow", "TextLabel"))
        self.label.setText(_translate("MainWindow", "Setpoint:"))
        self.label_2.setText(_translate("MainWindow", "Kp:"))
        self.label_4.setText(_translate("MainWindow", "Kd:"))
        self.label_3.setText(_translate("MainWindow", "Ki:"))
        self.label_6.setText(_translate("MainWindow", "Velocidade"))
        self.menuFile.setTitle(_translate("MainWindow", "Arquivo"))
        self.actionOpen.setText(_translate("MainWindow", "Abrir"))
        self.actionOpen.setShortcut(_translate("MainWindow", "Ctrl+O"))
        self.actionSave.setText(_translate("MainWindow", "Salvar"))
        self.actionSave.setShortcut(_translate("MainWindow", "Ctrl+S"))

from pyqtgraph import PlotWidget

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

