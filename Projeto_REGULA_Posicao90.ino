#include "VarSpeedServo.h"
//Definição dos objetos servos do braço robótico
VarSpeedServo servo1;//Servo
VarSpeedServo servo2;//Servo
VarSpeedServo servo3;//Servo
VarSpeedServo servo4;//Servo

void setup()
{
 //Anexa o objeto servo ao pino
 servo1.attach(6); //Servo, pino digital 6
 //Move todo o braco para posicao inicial
 servo1.write(90);//Servo
 servo2.attach(9);
 servo2.write(90);
 servo3.attach(10);
 servo3.write(90);
 servo4.attach(11);
 servo4.write(90);
 
 
}
void loop()
{
}
