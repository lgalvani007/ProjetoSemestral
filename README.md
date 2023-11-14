# Projeto Semestral

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

## Modelo
* Gm = tf(47.57,[0.1033 1 0])

## Comando pyqt5
* pyuic5 "[name].ui" -o "[name].py" -x

## Comando MatLab
t = 0:0.001:1; % Vetor de tempo

% Criar várias entradas
u1 = 50 * ones(size(t)); % Degrau unitário 50
u2 = 100 * ones(size(t)); % Degrau unitário com amplitude 100
u3 = 150 * ones(size(t)); % Degrau unitário com amplitude 150
u4 = 200 * ones(size(t)); % Degrau unitário com amplitude 200
u5 = 255 * ones(size(t)); % Degrau unitário com amplitude 255

% Plotar as entradas
plot(t, u1, 'r', 'LineWidth', 3)
hold on
plot(t, u2, 'g', 'LineWidth', 3)
plot(t, u3, 'b', 'LineWidth', 3)
plot(t, u4, 'm', 'LineWidth', 3)
plot(t, u5, 'y', 'LineWidth', 3);
title('Entradas do Sistema');
xlabel('Tempo (s)');
ylabel('Amplitude');
legend('Entrada: 50', 'Entrada: 100', 'Entrada: 150', 'Entrada: 200', 'Entrada: 255');
ylim([0,350])


## Links e Referências
*   (graficos no pyqt5)