import sys
sys.path.append("C:/Users/Leonardo/Desktop/4 ano/Orientada a obeto/ProjetoSemestral/windows")

import Menu, Posicao, Velocidade
from PyQt5 import QtCore, QtGui, QtWidgets
import serial

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
        self.ui_posicao.Simular.clicked.connect(self.simulaPosicao)
        
        self.ui_velocidade.Voltar.clicked.connect(self.abre_menu)
        self.ui_velocidade.InfoAtual.setText("Atual")
        self.ui_velocidade.InfoAnterior.setText("Anterior")
        self.ui_velocidade.Simular.clicked.connect(self.simulaVelocidade)
        
    def abre_menu(self):
        self.Dialog_menu.show()
        self.Dialog_velocidade.close()
        self.Dialog_posicao.close()
    
    def abre_velocidade(self):
        self.Dialog_velocidade.show()
        self.Dialog_posicao.close()
        self.Dialog_menu.close()
    
    def abre_posicao(self):
        self.Dialog_posicao.show()
        self.Dialog_velocidade.close()
        self.Dialog_menu.close()
        
    def simulaPosicao(self):
        tipo = 0
        setpoint = self.ui_posicao.Setpoint.value()
        kp = round(self.ui_posicao.Kp.value() * 1000)
        ki = round(self.ui_posicao.Ki.value() * 1000)
        kd = round(self.ui_posicao.Kd.value() * 1000)
        enviarSerial(tipo, setpoint, kp, ki, kd)
        lerSerial()
        self.ui_posicao.GraficoAtual.plot(time,data)
    
    def simulaVelocidade(self):
        tipo = 1
        setpoint = self.ui_velocidade.Setpoint.value()
        kp = round(self.ui_velocidade.Kp.value() * 1000)
        ki = round(self.ui_velocidade.Ki.value() * 1000)
        kd = round(self.ui_velocidade.Kd.value() * 1000)
        
        
        enviarSerial(tipo, setpoint, kp, ki, kd)
        lerSerial()
        self.ui_velocidade.GraficoAtual.plot([0,1],[0,1])
        

def enviarSerial(TYPE, SETPOINT, KP, KI, KD):
    mensagem = f"{TYPE},{SETPOINT},{KP},{KI},{KD}\n"
    porta_serial.write(mensagem.encode())
    print("Mensagem enviada com sucesso!")
    
        
def lerSerial():
    global time, data
    mensagem = " "
    while(mensagem == " "):
        mensagem = porta_serial.readline().decode()
    if(mensagem != b''.decode()):
        dados = mensagem.split(",")
        time = [float(dados[i]) for i in range(0, len(dados), 2)]
        data = [float(dados[i]) for i in range(1, len(dados), 2)]

        
if __name__ == "__main__":
    import sys
    global porta_serial
    porta_serial = serial.Serial('COM4', 9600)
    app = QtWidgets.QApplication(sys.argv)
    c = controller()
    c.abre_menu()
    sys.exit(app.exec_())
    porta_serial.close()
    
