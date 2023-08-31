# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Menu.ui'
#
# Created by: PyQt5 UI code generator 5.9.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_Menu(object):
    def setupUi(self, Menu):
        Menu.setObjectName("Menu")
        Menu.resize(1200, 800)
        Menu.setWindowOpacity(1.0)
        Menu.setAutoFillBackground(False)
        self.label = QtWidgets.QLabel(Menu)
        self.label.setGeometry(QtCore.QRect(50, 20, 1091, 361))
        font = QtGui.QFont()
        font.setPointSize(33)
        self.label.setFont(font)
        self.label.setFrameShadow(QtWidgets.QFrame.Plain)
        self.label.setLineWidth(0)
        self.label.setMidLineWidth(0)
        self.label.setTextFormat(QtCore.Qt.AutoText)
        self.label.setAlignment(QtCore.Qt.AlignCenter)
        self.label.setWordWrap(True)
        self.label.setObjectName("label")
        self.splitter = QtWidgets.QSplitter(Menu)
        self.splitter.setGeometry(QtCore.QRect(300, 350, 591, 301))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.splitter.sizePolicy().hasHeightForWidth())
        self.splitter.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(45)
        self.splitter.setFont(font)
        self.splitter.setFrameShape(QtWidgets.QFrame.NoFrame)
        self.splitter.setFrameShadow(QtWidgets.QFrame.Plain)
        self.splitter.setLineWidth(0)
        self.splitter.setMidLineWidth(0)
        self.splitter.setOrientation(QtCore.Qt.Vertical)
        self.splitter.setHandleWidth(24)
        self.splitter.setObjectName("splitter")
        self.Posicao = QtWidgets.QPushButton(self.splitter)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.Posicao.sizePolicy().hasHeightForWidth())
        self.Posicao.setSizePolicy(sizePolicy)
        self.Posicao.setSizeIncrement(QtCore.QSize(0, 0))
        self.Posicao.setIconSize(QtCore.QSize(16, 16))
        self.Posicao.setObjectName("Posicao")
        self.Velocidade = QtWidgets.QPushButton(self.splitter)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.Velocidade.sizePolicy().hasHeightForWidth())
        self.Velocidade.setSizePolicy(sizePolicy)
        self.Velocidade.setObjectName("Velocidade")

        self.retranslateUi(Menu)
        QtCore.QMetaObject.connectSlotsByName(Menu)

    def retranslateUi(self, Menu):
        _translate = QtCore.QCoreApplication.translate
        Menu.setWindowTitle(_translate("Menu", "Menu"))
        self.label.setText(_translate("Menu", "Simulação de controle de posição e velocidade de um motor DC com parametros interativos"))
        self.Posicao.setText(_translate("Menu", "Posição"))
        self.Velocidade.setText(_translate("Menu", "Velocidade"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    Menu = QtWidgets.QDialog()
    ui = Ui_Menu()
    ui.setupUi(Menu)
    Menu.show()
    sys.exit(app.exec_())

