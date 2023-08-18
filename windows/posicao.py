# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Posicao.ui'
#
# Created by: PyQt5 UI code generator 5.9.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_Posicao(object):
    def setupUi(self, Posicao):
        Posicao.setObjectName("Posicao")
        Posicao.resize(451, 400)
        self.Kp = QtWidgets.QDoubleSpinBox(Posicao)
        self.Kp.setGeometry(QtCore.QRect(70, 170, 62, 22))
        self.Kp.setDecimals(3)
        self.Kp.setSingleStep(0.001)
        self.Kp.setObjectName("Kp")
        self.Ki = QtWidgets.QDoubleSpinBox(Posicao)
        self.Ki.setGeometry(QtCore.QRect(70, 200, 62, 22))
        self.Ki.setDecimals(3)
        self.Ki.setSingleStep(0.001)
        self.Ki.setObjectName("Ki")
        self.Kd = QtWidgets.QDoubleSpinBox(Posicao)
        self.Kd.setGeometry(QtCore.QRect(70, 230, 61, 22))
        self.Kd.setDecimals(3)
        self.Kd.setSingleStep(0.001)
        self.Kd.setObjectName("Kd")
        self.Setpoint = QtWidgets.QSpinBox(Posicao)
        self.Setpoint.setGeometry(QtCore.QRect(70, 140, 61, 22))
        self.Setpoint.setMinimum(0)
        self.Setpoint.setMaximum(359)
        self.Setpoint.setObjectName("Setpoint")
        self.Simular = QtWidgets.QPushButton(Posicao)
        self.Simular.setGeometry(QtCore.QRect(10, 300, 121, 41))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.Simular.setFont(font)
        self.Simular.setObjectName("Simular")
        self.label = QtWidgets.QLabel(Posicao)
        self.label.setGeometry(QtCore.QRect(10, 140, 47, 13))
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(Posicao)
        self.label_2.setGeometry(QtCore.QRect(10, 170, 47, 13))
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(Posicao)
        self.label_3.setGeometry(QtCore.QRect(10, 200, 47, 13))
        self.label_3.setObjectName("label_3")
        self.label_4 = QtWidgets.QLabel(Posicao)
        self.label_4.setGeometry(QtCore.QRect(10, 230, 47, 13))
        self.label_4.setObjectName("label_4")
        self.Voltar = QtWidgets.QPushButton(Posicao)
        self.Voltar.setGeometry(QtCore.QRect(10, 50, 121, 41))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.Voltar.setFont(font)
        self.Voltar.setObjectName("Voltar")
        self.InfoAtual = QtWidgets.QLabel(Posicao)
        self.InfoAtual.setGeometry(QtCore.QRect(150, 180, 291, 16))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.InfoAtual.setFont(font)
        self.InfoAtual.setObjectName("InfoAtual")
        self.InfoAnterior = QtWidgets.QLabel(Posicao)
        self.InfoAnterior.setGeometry(QtCore.QRect(150, 380, 291, 16))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.InfoAnterior.setFont(font)
        self.InfoAnterior.setObjectName("InfoAnterior")
        self.line = QtWidgets.QFrame(Posicao)
        self.line.setGeometry(QtCore.QRect(130, 0, 16, 401))
        self.line.setFrameShadow(QtWidgets.QFrame.Plain)
        self.line.setLineWidth(1)
        self.line.setFrameShape(QtWidgets.QFrame.VLine)
        self.line.setObjectName("line")
        self.label_5 = QtWidgets.QLabel(Posicao)
        self.label_5.setGeometry(QtCore.QRect(10, 10, 121, 31))
        font = QtGui.QFont()
        font.setPointSize(18)
        self.label_5.setFont(font)
        self.label_5.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.label_5.setLineWidth(1)
        self.label_5.setAlignment(QtCore.Qt.AlignCenter)
        self.label_5.setObjectName("label_5")
        self.GraficoAtual = PlotWidget(Posicao)
        self.GraficoAtual.setGeometry(QtCore.QRect(150, 10, 291, 161))
        self.GraficoAtual.setObjectName("GraficoAtual")
        self.GraficoAnterior = PlotWidget(Posicao)
        self.GraficoAnterior.setGeometry(QtCore.QRect(150, 210, 291, 161))
        self.GraficoAnterior.setObjectName("GraficoAnterior")

        self.retranslateUi(Posicao)
        QtCore.QMetaObject.connectSlotsByName(Posicao)

    def retranslateUi(self, Posicao):
        _translate = QtCore.QCoreApplication.translate
        Posicao.setWindowTitle(_translate("Posicao", "Dialog"))
        self.Simular.setText(_translate("Posicao", "Simular"))
        self.label.setText(_translate("Posicao", "Setpoint:"))
        self.label_2.setText(_translate("Posicao", "Kp:"))
        self.label_3.setText(_translate("Posicao", "Ki:"))
        self.label_4.setText(_translate("Posicao", "Kd:"))
        self.Voltar.setText(_translate("Posicao", "Voltar"))
        self.InfoAtual.setText(_translate("Posicao", "TextLabel"))
        self.InfoAnterior.setText(_translate("Posicao", "TextLabel"))
        self.label_5.setText(_translate("Posicao", "Posição"))

from pyqtgraph import PlotWidget

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    Posicao = QtWidgets.QDialog()
    ui = Ui_Posicao()
    ui.setupUi(Posicao)
    Posicao.show()
    sys.exit(app.exec_())

