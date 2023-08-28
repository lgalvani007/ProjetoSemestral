# Projeto Semestral Orientada a Objeto

Simulador de controle de velocidade e posição de uma roda de inércia.

## Materiais
* Motor com encoder
* Ponte H
* Raspberry pi pico
* Fonte
* Interface gráfica   
* Comunicação Serial

## funcionamento
* Python
    * Interface Gráfica
        * Janela de seleção
            * Controle de velocidade
                * Kp, Ki, Kd, SETPOINT, espaço para valores
                * Gráficos (2)
                * -12 a 12 -> -600 a 600 RPM
            * Controle de posição
                * Kp, Ki, Kd, SETPOINT, espaço para valores
                * Gráficos (2)
        * Botão para simulação
            * Envia pacote de dados (SETPOINT, Kp, Ki, Kd, tipo de controle(V ou P))
        * Recebe informações e exibe (Velocidades/Posições, tempo)
* Micocontrolador
    * FUNÇÕES
        * moveMotor(me, md)
        * controlador
        * leitor do pacote serial
        * envio de pacote de dados
    * MOTOR
        Fio | Função
        ----|----
        Preto|M+
        Vermelho|M-
        Amarelo|ENC A
        Branco|ENC B
        Azul|+5V
        Verde|GND
        * teste
    * While (enquanto não receber pacote de informações)
    * executa a malha de controle especifica e pega dados ao mesmo tempo
    * Transforma dados (velocidade (rad/s) e posição(°))
    * envia dados (pacote de dados)

## Tasks
* Testar encoder (testEncoder)
    * Ver quantos pulsos tem uma volta - 1200
    * Ver a função getVelocity e getPosition - ok
    * Implementar no MotorControl
    * Implemntar os dois PIDs 
    * Atualizar sendMensage()

## Comando pyqt5
* pyuic5 "[name].ui" -o "[name].py" -x

## Links e Referências
*   (graficos no pyqt5)