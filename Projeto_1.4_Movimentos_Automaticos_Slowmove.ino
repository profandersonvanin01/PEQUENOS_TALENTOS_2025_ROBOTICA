/* MakerQuest - Projeto_1.4_Movimentos_Automáticos_Slowmove - Versão:1.0 Ago24 */
/*            Manuais&Códigos disponíveis em www.makerquest.com.br             */

#include <VarSpeedServo.h>

// Definição dos objetos servos do braço robótico usando a biblioteca VarSpeedServo
VarSpeedServo servo1;  // BASE
VarSpeedServo servo2;  // OMBRO
VarSpeedServo servo3;  // COTOVELO
VarSpeedServo servo4;  // GARRA

// Variáveis - Teste combinações de velocidade e delay, altere o movSpeed e delayTime e faça o upload do código.
// Exemplos:
// moveSpeed = 30 e delayTime = 15
// moveSpeed = 20 e delayTime = 25
// moveSpeed = 55 e delayTime = 6
// moveSpeed = 60 e delayTime = 5
 
const int moveSpeed = 50;   // Velocidade dos movimentos dos servos (0-255)                      
const unsigned long delayTime = 15; // Tempo de delay para os servos alcançarem a posição (em ms)



unsigned long previousMillis = 0;   // Armazena o tempo do último movimento
int pos = 0;            // Variável para armazenar a posição do servo

// Função para mover o servo suavemente
void moveServo(VarSpeedServo &servo, int startPos, int endPos) {
  if (startPos < endPos) {
    for (pos = startPos; pos <= endPos; pos++) {
      servo.slowmove(pos, moveSpeed);
      delay(delayTime); // Ajuste o delay conforme necessário
    }
  } else {
    for (pos = startPos; pos >= endPos; pos--) {
      servo.slowmove(pos, moveSpeed);
      delay(delayTime); // Ajuste o delay conforme necessário
    }
  }
}

// Função para sincronizar movimentos dos servos 
void moveServosInSync() {
  moveServo(servo1, 45, 90);   // BASE
  moveServo(servo2, 90, 135);  // OMBRO
  moveServo(servo3, 60, 75);   // COTOVELO
  moveServo(servo4, 160, 110); // GARRA
  
  moveServo(servo1, 90, 45);   // BASE
  moveServo(servo2, 135, 90);  // OMBRO
  moveServo(servo3, 75, 60);   // COTOVELO
  moveServo(servo4, 110, 160); // GARRA
}

void setup() {
  // Anexa o objeto servo ao pino
  servo1.attach(11);  
  servo2.attach(10);  
  servo3.attach(9);   
  servo4.attach(6);  
  
  // Configura as posições iniciais dos servos
  servo1.write(45);  
  servo2.write(90);  
  servo3.write(60);  
  servo4.write(160);
  
  // Aguarda um tempo para garantir que os servos estejam na posição inicial
  delay(2000);
}

void loop() {
  unsigned long currentMillis = millis();

  // Executa a sequência de movimentos dos servos
  moveServosInSync();

  // Aguarda um tempo antes de reiniciar a sequência
  while (millis() - currentMillis < 2000) {
    // Loop de espera não bloqueante
  }
}
/* MakerQuest - Projeto_1.4_Movimentos_Automáticos_Slowmove - Versão:1.0 Ago24 */
/*            Manuais&Códigos disponíveis em www.makerquest.com.br             */