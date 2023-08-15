import sys
sys.path.append("C:/Users/Leonardo/Desktop/4 ano/Orientada a obeto/ProjetoSemestral/windows")

import Menu, Posicao, Velocidade
from PyQt5 import QtCore, QtGui, QtWidgets

class controller():
    def __init__(self):
        self.Dialog_posicao = QtWidgets.QDialog()
        self.ui_posicao = Posicao.Ui_Posicao()
        self.ui_posicao.setupUi(self.Dialog_posicao)

        self.Dialog_velocidade = QtWidgets.QDialog()
        self.ui_velocidade = Velocidade.Ui_Velocidade()
        self.ui_velocidade.setupUi(self.Dialog_velocidade)

        self.Dialog_menu = QtWidgets.QDialog()
        self.ui_menu = Menu.Ui_Menu()
        self.ui_menu.setupUi(self.Dialog_menu)
        
        #
        
        self.ui_menu.Posicao.clicked.connect(self.abre_posicao)
        self.ui_menu.Velocidade.clicked.connect(self.abre_velocidade)
        
        self.ui_posicao.Voltar.clicked.connect(self.abre_menu)
        self.ui_posicao.InfoAtual.setText("Atual")
        self.ui_posicao.InfoAnterior.setText("Anterior")
        
        self.ui_velocidade.Voltar.clicked.connect(self.abre_menu)
        self.ui_velocidade.InfoAtual.setText("Atual")
        self.ui_velocidade.InfoAnterior.setText("Anterior")
        
    def abre_menu(self):
        self.Dialog_velocidade.close()
        self.Dialog_posicao.close()
        self.Dialog_menu.show()
    
    def abre_velocidade(self):
        self.Dialog_velocidade.show()
        self.Dialog_posicao.close()
        self.Dialog_menu.close()
    
    def abre_posicao(self):
        self.Dialog_velocidade.close()
        self.Dialog_posicao.show()
        self.Dialog_menu.close()

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    c = controller()
    c.abre_menu()
    sys.exit(app.exec_())