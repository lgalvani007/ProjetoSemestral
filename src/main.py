import sys
sys.path.append("C:/Users/Leonardo/Desktop/4 ano/Orientada a obeto/ProjetoSemestral/windows")

import Menu, Posicao, Velocidade
from PyQt5 import QtWidgets, QtCore
from PyQt5.QtWidgets import QMainWindow, QApplication, QAction, QFileDialog
import serial
import pyqtgraph as pg
import os

class ComunicacaoSerial:
    def __init__(self, porta, velocidade):
        self.porta_serial = serial.Serial(porta, velocidade)

    def enviarSerial(self, TYPE, SETPOINT, KP, KI, KD):
        mensagem = f"{TYPE},{SETPOINT},{KP},{KI},{KD}\n"
        self.porta_serial.write(mensagem.encode())
    
    def lerSerial(self):
        mensagem = " "
        while(mensagem == " "):
            mensagem = self.porta_serial.readline().decode()
        if(mensagem != b''.decode()):
            dados = mensagem.split(",")
            data = [float(dados[i]) for i in range(0, len(dados), 2)]
            time = [float(dados[i])/1000.0 for i in range(1, len(dados), 2)]
        return time, data
        
    def fechaPorta(self):
        self.porta_serial.close()

class controller():
    def __init__(self, Serial):
        self.serial = Serial
        self.Dialog_posicao = QtWidgets.QMainWindow()
        self.ui_posicao = Posicao.Ui_MainWindow()
        self.ui_posicao.setupUi(self.Dialog_posicao)

        self.Dialog_velocidade = QtWidgets.QMainWindow()
        self.ui_velocidade = Velocidade.Ui_MainWindow()
        self.ui_velocidade.setupUi(self.Dialog_velocidade)

        self.Dialog_menu = QtWidgets.QDialog()
        self.ui_menu = Menu.Ui_Menu()
        self.ui_menu.setupUi(self.Dialog_menu)

        self.tipo_atual_velocidade = 0
        self.setpoint_atual_velocidade = 0
        self.kp_atual_velocidade = 0
        self.ki_atual_velocidade = 0
        self.kd_atual_velocidade = 0
        
        self.tipo_atual_posicao = 0
        self.setpoint_atual_posicao = 0
        self.kp_atual_posicao = 0
        self.ki_atual_posicao = 0
        self.kd_atual_posicao = 0
        
        self.tipo_anterior_velocidade = 0
        self.setpoint_anterior_velocidade = 0
        self.kp_anterior_velocidade = 0
        self.ki_anterior_velocidade = 0
        self.kd_anterior_velocidade = 0
        
        self.tipo_anterior_posicao = 0
        self.setpoint_anterior_posicao = 0
        self.kp_anterior_posicao = 0
        self.ki_anterior_posicao = 0
        self.kd_anterior_posicao = 0
        
        
        self.time_atual_velocidade = []
        self.data_atual_velocidade = []
        self.time_atual_posicao = []
        self.data_atual_posicao = []
        self.time_anterior_velocidade = []
        self.data_anterior_velocidade = []
        self.time_anterior_posicao = []
        self.data_anterior_posicao = []
        self.data_setpoint_atual_posicao = []
        self.data_setpoint_atual_velocidade = []
        self.data_setpoint_anterior_posicao = []
        self.data_setpoint_anterior_velocidade = []
        
        self.nVelocidade = 0
        self.nPosicao = 0
        
        self.pen_data = pg.mkPen(color=(255, 0, 0), width=2)
        self.pen_setpoint = pg.mkPen(color=(0, 255, 0), width=2, style=QtCore.Qt.DashLine)
        
        self.ui_menu.Posicao.clicked.connect(self.abre_posicao)
        self.ui_menu.Velocidade.clicked.connect(self.abre_velocidade)
        
        self.ui_posicao.Voltar.clicked.connect(self.abre_menu)
        self.ui_posicao.InfoAtual.setText("Atual")
        self.ui_posicao.InfoAnterior.setText("Anterior")
        self.ui_posicao.statusbar.showMessage('Pronto!')
        self.ui_posicao.Simular.clicked.connect(self.simulaPosicao)
        self.ui_posicao.actionSalvar.triggered.connect(self.saveFileDialogPosicao)
        self.ui_posicao.actionAbrir.triggered.connect(self.openFileDialogPosicao)
        
        self.ui_velocidade.Voltar.clicked.connect(self.abre_menu)
        self.ui_velocidade.InfoAtual.setText("Atual")
        self.ui_velocidade.InfoAnterior.setText("Anterior")
        self.ui_velocidade.statusbar.showMessage('Pronto!')
        self.ui_velocidade.Simular.clicked.connect(self.simulaVelocidade)
        self.ui_velocidade.actionSave.triggered.connect(self.saveFileDialogVelocidade)
        self.ui_velocidade.actionOpen.triggered.connect(self.openFileDialogVelocidade)
        
        self.ui_velocidade.GraficoAtual.setBackground('w')
        self.ui_velocidade.GraficoAnterior.setBackground('w')
        self.ui_posicao.GraficoAtual.setBackground('w')
        self.ui_posicao.GraficoAnterior.setBackground('w')
        self.ui_velocidade.GraficoAtual.addLegend()
        self.ui_velocidade.GraficoAnterior.addLegend()
        self.ui_posicao.GraficoAtual.addLegend()
        self.ui_posicao.GraficoAnterior.addLegend()

        self.desktop_path = os.path.join(os.path.expanduser("~"), "Desktop")

    def saveFileDialogPosicao(self):
        fileName, _ = QFileDialog.getSaveFileName(self.Dialog_posicao,
        "Salvar",self.desktop_path,"Documentos de texto (*.txt)")
        if not(fileName.endswith(".txt")):
            fileName = fileName + ".txt"
        try:
            f = open(fileName,'w')
            text = f"kp:{self.kp_atual_posicao/1000}\nki:{self.ki_atual_posicao/1000}\nkd:{self.kd_atual_posicao/1000}\n"
            f.write(text)
            f.close()
        except:
            pass

    def saveFileDialogVelocidade(self):
        fileName, _ = QFileDialog.getSaveFileName(self.Dialog_velocidade,
        "Salvar",self.desktop_path,"Documentos de texto (*.txt)")
        if not(fileName.endswith(".txt")):
            fileName = fileName + ".txt"
        try:
            f = open(fileName,'w')
            text = f"kp:{self.kp_atual_velocidade/1000}\nki:{self.ki_atual_velocidade/1000}\nkd:{self.kd_atual_velocidade/1000}\n"
            f.write(text)
            f.close()
        except:
            pass

    def openFileDialogPosicao(self):
        fname = QFileDialog.getOpenFileName(self.Dialog_posicao, "Abrir",
        self.desktop_path,"Documentos de texto (*.txt)")
        try:
            if fname[0]:
                f = open(fname[0], 'r')
            with f:
                data = f.read()
                data = self.separaTexto(data)
                self.ui_posicao.Kp.setValue(data[0])
                self.ui_posicao.Ki.setValue(data[1])
                self.ui_posicao.Kd.setValue(data[2])
        except:
            pass
    
    def openFileDialogVelocidade(self):
            fname = QFileDialog.getOpenFileName(self.Dialog_velocidade, "Abrir",
            self.desktop_path,"Documentos de texto (*.txt)")
            try:
                if fname[0]:
                    f = open(fname[0], 'r')
                with f:
                    data = f.read()
                    data = self.separaTexto(data)
                    self.ui_velocidade.Kp.setValue(data[0])
                    self.ui_velocidade.Ki.setValue(data[1])
                    self.ui_velocidade.Kd.setValue(data[2])
            except:
                pass

    def separaTexto(self,text):
        linhas = text.strip().split('\n')
        valores = []
        for linha in linhas:
            chave, valor = linha.split(':')
            valores.append(float(valor))
        return valores

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
        self.ui_posicao.statusbar.showMessage('Simulando...')
        self.ui_posicao.statusbar.repaint()
        self.atualizaPosicao()
        self.tipo_atual_posicao = 0
        self.setpoint_atual_posicao = self.ui_posicao.Setpoint.value()
        self.kp_atual_posicao = round(self.ui_posicao.Kp.value() * 1000)
        self.ki_atual_posicao = round(self.ui_posicao.Ki.value() * 1000)
        self.kd_atual_posicao = round(self.ui_posicao.Kd.value() * 1000)
        self.serial.enviarSerial(self.tipo_atual_posicao, self.setpoint_atual_posicao, self.kp_atual_posicao, self.ki_atual_posicao, self.kd_atual_posicao)
        Time, Data = self.serial.lerSerial()
        if(self.nPosicao > 0):
            self.ui_posicao.GraficoAnterior.clear()
            self.ui_posicao.GraficoAnterior.plot(self.time_anterior_posicao, self.data_anterior_posicao, name = "velocidade", pen = self.pen_data)
            self.ui_posicao.GraficoAnterior.plot(self.time_anterior_posicao, self.data_setpoint_anterior_posicao, name = "setPoint", pen = self.pen_setpoint)
            self.ui_posicao.InfoAnterior.setText(f"SetPoint: {self.setpoint_anterior_posicao}, Kp: {self.kp_anterior_posicao}, Ki: {self.ki_anterior_posicao}, Kd: {self.kd_anterior_posicao}")
        self.data_atual_posicao = Data
        self.time_atual_posicao = Time
        self.data_setpoint_atual_posicao = [self.setpoint_atual_posicao] * len(self.data_atual_posicao)
        self.ui_posicao.GraficoAtual.clear()
        self.ui_posicao.GraficoAtual.plot(self.time_atual_posicao, self.data_atual_posicao, name = "velocidade", pen = self.pen_data)
        self.ui_posicao.GraficoAtual.plot(self.time_atual_posicao, self.data_setpoint_atual_posicao, name = "setPoint", pen = self.pen_setpoint)
        self.ui_posicao.InfoAtual.setText(f"SetPoint: {self.setpoint_atual_posicao}, Kp: {self.kp_atual_posicao/1000}, Ki: {self.ki_atual_posicao/1000}, Kd: {self.kd_atual_posicao/1000}")
        self.nPosicao += 1
        self.ui_posicao.statusbar.showMessage('Pronto!')
        
    
    def simulaVelocidade(self):
        self.ui_velocidade.statusbar.showMessage('Simulando...')
        self.ui_velocidade.statusbar.repaint()
        self.atualizaVelocidade()
        self.tipo_atual_velocidade = 1
        self.setpoint_atual_velocidade = self.ui_velocidade.Setpoint.value()
        self.kp_atual_velocidade = round(self.ui_velocidade.Kp.value() * 1000)
        self.ki_atual_velocidade = round(self.ui_velocidade.Ki.value() * 1000)
        self.kd_atual_velocidade = round(self.ui_velocidade.Kd.value() * 1000)
        self.serial.enviarSerial(self.tipo_atual_velocidade, self.setpoint_atual_velocidade, self.kp_atual_velocidade, self.ki_atual_velocidade, self.kd_atual_velocidade)
        Time, Data = self.serial.lerSerial()
        if(self.nVelocidade > 0):
            self.ui_velocidade.GraficoAnterior.clear()
            self.ui_velocidade.GraficoAnterior.plot(self.time_anterior_velocidade, self.data_anterior_velocidade, name = "velocidade", pen = self.pen_data)
            self.ui_velocidade.GraficoAnterior.plot(self.time_anterior_velocidade, self.data_setpoint_anterior_velocidade, name = "setPoint", pen = self.pen_setpoint)
            self.ui_velocidade.InfoAnterior.setText(f"SetPoint: {self.setpoint_anterior_velocidade}, Kp: {self.kp_anterior_velocidade}, Ki: {self.ki_anterior_velocidade}, Kd: {self.kd_anterior_velocidade}")
        self.data_atual_velocidade = Data
        self.time_atual_velocidade = Time
        self.data_setpoint_atual_velocidade = [self.setpoint_atual_velocidade] * len(self.data_atual_velocidade)
        self.ui_velocidade.GraficoAtual.clear()
        self.ui_velocidade.GraficoAtual.plot(self.time_atual_velocidade, self.data_atual_velocidade, name = "velocidade", pen = self.pen_data)
        self.ui_velocidade.GraficoAtual.plot(self.time_atual_velocidade, self.data_setpoint_atual_velocidade, name = "setPoint", pen = self.pen_setpoint)  
        self.ui_velocidade.InfoAtual.setText(f"SetPoint: {self.setpoint_atual_velocidade}, Kp: {self.kp_atual_velocidade/1000}, Ki: {self.ki_atual_velocidade/1000}, Kd: {self.kd_atual_velocidade/1000}")
        self.nVelocidade += 1
        self.ui_velocidade.statusbar.showMessage('Pronto!')
        
    def atualizaVelocidade(self):
        self.data_anterior_velocidade = self.data_atual_velocidade
        self.time_anterior_velocidade = self.time_atual_velocidade
        self.data_setpoint_anterior_velocidade = self.data_setpoint_atual_velocidade
        self.setpoint_anterior_velocidade = self.setpoint_atual_velocidade
        self.kp_anterior_velocidade = self.kp_atual_velocidade/1000
        self.ki_anterior_velocidade = self.ki_atual_velocidade/1000
        self.kd_anterior_velocidade = self.kd_atual_velocidade/1000
        
    def atualizaPosicao(self):
        self.data_anterior_posicao = self.data_atual_posicao
        self.time_anterior_posicao = self.time_atual_posicao
        self.data_setpoint_anterior_posicao = self.data_setpoint_atual_posicao
        self.setpoint_anterior_posicao = self.setpoint_atual_posicao
        self.kp_anterior_posicao = self.kp_atual_posicao/1000
        self.ki_anterior_posicao = self.ki_atual_posicao/1000
        self.kd_anterior_posicao = self.kd_atual_posicao/1000

if __name__ == "__main__":
    import sys
    minha_comunicacao = ComunicacaoSerial('COM6', 9600)
    app = QtWidgets.QApplication(sys.argv)
    c = controller(minha_comunicacao)
    c.abre_menu()
    app.exec_()
    minha_comunicacao.fechaPorta()
    sys.exit()
    
    