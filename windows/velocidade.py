# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Velocidade.ui'
#
# Created by: PyQt5 UI code generator 5.9.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_Velocidade(object):
    def setupUi(self, Velocidade):
        Velocidade.setObjectName("Velocidade")
        Velocidade.resize(1200, 800)
        self.Kp = QtWidgets.QDoubleSpinBox(Velocidade)
        self.Kp.setGeometry(QtCore.QRect(70, 270, 62, 22))
        self.Kp.setDecimals(3)
        self.Kp.setSingleStep(0.001)
        self.Kp.setObjectName("Kp")
        self.Ki = QtWidgets.QDoubleSpinBox(Velocidade)
        self.Ki.setGeometry(QtCore.QRect(70, 300, 62, 22))
        self.Ki.setDecimals(3)
        self.Ki.setSingleStep(0.001)
        self.Ki.setObjectName("Ki")
        self.Kd = QtWidgets.QDoubleSpinBox(Velocidade)
        self.Kd.setGeometry(QtCore.QRect(70, 330, 61, 22))
        self.Kd.setDecimals(3)
        self.Kd.setSingleStep(0.001)
        self.Kd.setProperty("value", 0.0)
        self.Kd.setObjectName("Kd")
        self.Setpoint = QtWidgets.QSpinBox(Velocidade)
        self.Setpoint.setGeometry(QtCore.QRect(70, 240, 61, 22))
        self.Setpoint.setMinimum(-255)
        self.Setpoint.setMaximum(255)
        self.Setpoint.setObjectName("Setpoint")
        self.Simular = QtWidgets.QPushButton(Velocidade)
        self.Simular.setGeometry(QtCore.QRect(10, 400, 121, 41))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.Simular.setFont(font)
        self.Simular.setObjectName("Simular")
        self.label = QtWidgets.QLabel(Velocidade)
        self.label.setGeometry(QtCore.QRect(10, 240, 47, 13))
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(Velocidade)
        self.label_2.setGeometry(QtCore.QRect(10, 270, 47, 13))
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(Velocidade)
        self.label_3.setGeometry(QtCore.QRect(10, 300, 47, 13))
        self.label_3.setObjectName("label_3")
        self.label_4 = QtWidgets.QLabel(Velocidade)
        self.label_4.setGeometry(QtCore.QRect(10, 330, 47, 13))
        self.label_4.setObjectName("label_4")
        self.Voltar = QtWidgets.QPushButton(Velocidade)
        self.Voltar.setGeometry(QtCore.QRect(10, 150, 121, 41))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.Voltar.setFont(font)
        self.Voltar.setObjectName("Voltar")
        self.InfoAtual = QtWidgets.QLabel(Velocidade)
        self.InfoAtual.setGeometry(QtCore.QRect(150, 370, 291, 16))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.InfoAtual.setFont(font)
        self.InfoAtual.setObjectName("InfoAtual")
        self.InfoAnterior = QtWidgets.QLabel(Velocidade)
        self.InfoAnterior.setGeometry(QtCore.QRect(150, 760, 291, 16))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.InfoAnterior.setFont(font)
        self.InfoAnterior.setObjectName("InfoAnterior")
        self.line = QtWidgets.QFrame(Velocidade)
        self.line.setGeometry(QtCore.QRect(130, 0, 16, 801))
        self.line.setFrameShadow(QtWidgets.QFrame.Plain)
        self.line.setLineWidth(1)
        self.line.setFrameShape(QtWidgets.QFrame.VLine)
        self.line.setObjectName("line")
        self.label_6 = QtWidgets.QLabel(Velocidade)
        self.label_6.setGeometry(QtCore.QRect(10, 110, 121, 31))
        font = QtGui.QFont()
        font.setPointSize(18)
        self.label_6.setFont(font)
        self.label_6.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.label_6.setLineWidth(1)
        self.label_6.setAlignment(QtCore.Qt.AlignCenter)
        self.label_6.setObjectName("label_6")
        self.GraficoAtual = PlotWidget(Velocidade)
        self.GraficoAtual.setGeometry(QtCore.QRect(150, 10, 1041, 341))
        self.GraficoAtual.setObjectName("GraficoAtual")
        self.GraficoAnterior = PlotWidget(Velocidade)
        self.GraficoAnterior.setGeometry(QtCore.QRect(150, 400, 1041, 341))
        self.GraficoAnterior.setObjectName("GraficoAnterior")
        self.Salvar = QtWidgets.QPushButton(Velocidade)
        self.Salvar.setGeometry(QtCore.QRect(10, 540, 121, 41))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.Salvar.setFont(font)
        self.Salvar.setObjectName("Salvar")
        self.Status = QtWidgets.QLabel(Velocidade)
        self.Status.setGeometry(QtCore.QRect(10, 450, 121, 31))
        font = QtGui.QFont()
        font.setPointSize(16)
        self.Status.setFont(font)
        self.Status.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.Status.setAlignment(QtCore.Qt.AlignCenter)
        self.Status.setObjectName("Status")

        self.retranslateUi(Velocidade)
        QtCore.QMetaObject.connectSlotsByName(Velocidade)

    def retranslateUi(self, Velocidade):
        _translate = QtCore.QCoreApplication.translate
        Velocidade.setWindowTitle(_translate("Velocidade", "Dialog"))
        self.Simular.setText(_translate("Velocidade", "Simular"))
        self.label.setText(_translate("Velocidade", "Setpoint:"))
        self.label_2.setText(_translate("Velocidade", "Kp:"))
        self.label_3.setText(_translate("Velocidade", "Ki:"))
        self.label_4.setText(_translate("Velocidade", "Kd:"))
        self.Voltar.setText(_translate("Velocidade", "Voltar"))
        self.InfoAtual.setText(_translate("Velocidade", "TextLabel"))
        self.InfoAnterior.setText(_translate("Velocidade", "TextLabel"))
        self.label_6.setText(_translate("Velocidade", "Velocidade"))
        self.Salvar.setText(_translate("Velocidade", "Salvar"))
        self.Status.setText(_translate("Velocidade", "TextLabel"))

from pyqtgraph import PlotWidget

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    Velocidade = QtWidgets.QDialog()
    ui = Ui_Velocidade()
    ui.setupUi(Velocidade)
    Velocidade.show()
    sys.exit(app.exec_())

