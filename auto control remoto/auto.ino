#include <LEANTEC_ControlMotor.h>

const int EchoPin = 8;
const int TriggerPin = 9;
const int LedPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(LedPin, OUTPUT);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);


  //Configuramos los pines como salida
  pinMode(MotorDer1, OUTPUT); 
  pinMode(MotorDer2, OUTPUT);
  pinMode(MotorIzq1, OUTPUT); 
  pinMode(MotorIzq2, OUTPUT); 
  pinMode(PWM_Derecho, OUTPUT);
  pinMode(PWM_Izquierdo, OUTPUT);
}



int ping(int TriggerPin, int EchoPin) {
  long duration, distanceCm;

  digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
  delayMicroseconds(4);
  digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);

  duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos

  distanceCm = duration * 10 / 292 / 2;  //convertimos a distancia, en cm
  return distanceCm;

}

ControlMotor control(2,3,7,4,5,6); 
int MotorDer1=2;//El pin 2 de arduino se conecta con el pin In1 del L298N
int MotorDer2=3;//El pin 3 de arduino se conecta con el pin In2 del L298N
int MotorIzq1=7;//El pin 7 de arduino se conecta con el pin In3 del L298N
int MotorIzq2=4;//El pin 4 de arduino se conecta con el pin In4 del L298N
int PWM_Derecho=5;//El pin 5 de arduino se conecta con el pin EnA del L298N
int PWM_Izquierdo=6;//El pin 6 de arduino se conecta con el pin EnB del L298N

int velocidad=150;//Declaramos una variable para guardar la velocidad


} 
void derecha_antihorario_izquierda_horario(){ 
/*En esta fución la rueda derecha girará en sentido antihorario y la
izquierda en sentido horario.
En este caso, si las ruedas estuvieran en el chasis de un robot, el
robot retrocederia.*/
  digitalWrite(MotorDer1,HIGH);
  digitalWrite(MotorDer2,LOW);
  digitalWrite(MotorIzq1,HIGH);
  digitalWrite(MotorIzq2,LOW);
  analogWrite(PWM_Derecho,200);//Velocidad motor derecho 200
  analogWrite(PWM_Izquierdo,200);//Velocidad motor izquierdo 200

}
void derecha_horario_izquierda_antihorario(){ 
/*En esta fución la rueda derecha girará en sentido horario y la
izquierda en sentido antihorario.
En este caso, si las ruedas estuvieran en el chasis de un robot, el
robot avanzaría.*/  
  digitalWrite(MotorDer1,LOW);
  digitalWrite(MotorDer2,HIGH);
  digitalWrite(MotorIzq1,LOW);
  digitalWrite(MotorIzq2,HIGH);
  analogWrite(PWM_Derecho,200);//Velocidad motor derecho 200
  analogWrite(PWM_Izquierdo,200);//Velocidad motor izquierdo 200

}
void giro_horario(){ 
/*En esta fución ambas ruedas girarán en sentido horario.
En este caso, si las ruedas estuvieran en el chasis de un robot, el
robot giraria a la derecha.*/
  digitalWrite(MotorDer1,HIGH);
  digitalWrite(MotorDer2,LOW);
  digitalWrite(MotorIzq1,LOW);
  digitalWrite(MotorIzq2,HIGH);
  analogWrite(PWM_Derecho,200);//Velocidad motor derecho 200
  analogWrite(PWM_Izquierdo,200);//Velocidad motor izquierdo 200

}
void giro_antihorario(){ 
/*En esta fución ambas ruedas girarán en sentido antihorario.
En este caso, si las ruedas estuvieran en el chasis de un robot, el
robot giraria a la izquierda.*/
  digitalWrite(MotorDer1,LOW);
  digitalWrite(MotorDer2,HIGH);
  digitalWrite(MotorIzq1,HIGH);
  digitalWrite(MotorIzq2,LOW);
  analogWrite(PWM_Derecho,200);//Velocidad motor derecho 200
  analogWrite(PWM_Izquierdo,200);//Velocidad motor izquierdo 200

}
void parar(){ 
/*Función para que las ruedas paren*/
  digitalWrite(MotorDer1,LOW);
  digitalWrite(MotorDer2,LOW);
  digitalWrite(MotorIzq1,LOW);
  digitalWrite(MotorIzq2,LOW);
  analogWrite(PWM_Derecho,200);//Velocidad motor derecho 200
  analogWrite(PWM_Izquierdo,200);//Velocidad motor izquierdo 200

}


void loop() {
  int cm = ping(TriggerPin, EchoPin);
  Serial.print("Distancia: ");
  Serial.println(cm);
  delay(1000);

giro_horario();//Llamamos a la función giro_horario
delay(3000);//Durante 3 segundos ejecutamos esa función
giro_antihorario();//Llamamos a la función giro_antihorario
delay(3000);//Durante 3 segundos ejecutamos esa función
derecha_horario_izquierda_antihorario();//Llamamos a la función derecha_horario_izquierda_antihorario
delay(3000);//Durante 3 segundos ejecutamos esa función
derecha_antihorario_izquierda_horario();//Llamamos a la función derecha_antihorario_izquierda_horario
delay(3000);//Durante 3 segundos ejecutamos esa función
parar();//Llamamos a la función parar
delay(3000);//Durante 3 segundos ejecutamos esa función


}
