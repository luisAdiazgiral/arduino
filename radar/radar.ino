/*
Codigo originalmente creado por Dejan Nedelkovski de howtomechatronics.com
Traducido y modificado por El Taller de TD de youtube/eltallerdetd
*/

// Importa la libreria Servo
#include <Servo.h>. 

// Define los pines del sensor ultrasonico Trig y Echo
const int trigPin = 10;
const int echoPin = 11;
// Variables de duracion y distancia
long duration;
int distance;

Servo myServo; // Crea el objeto myServo

void setup() {
  pinMode(trigPin, OUTPUT); // Setea el pin trigPin como un Output
  pinMode(echoPin, INPUT); // Setea el pin echoPin como un Input
  Serial.begin(9600);
  myServo.attach(12); // Define en que pin esta conectado el Servo motor
  pinMode(8, OUTPUT); //Setea el pin 8 del buzzer como output
}
void loop() {
  // Rota el servo de 15 a 165 grados
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();//  Llama a esta funcion para calcular la distancia por cada grado
  Serial.print(i); // Envia el grado de inclinacion actual al puerto serial
  Serial.print(","); // Envia una , como caracter de separacion
  Serial.print(distance); // Envia la distancia al puerto serial
  Serial.print("."); // Envia un . como final de la orden

   if(distance<20){ // Si la distancia es menor a 20cm el ruido sera mas agudo que si la distancia esta entre mayor a 20 y menor a 40
    tone(8, 500, 100);
  }else if(distance>20 && distance<40){
    tone(8, 200, 100);
  }
}
  
  // Repite las lineas previas y hace que ahora el servo vaya de 165 a 15 grados
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
   
   if(distance<20){ // Si la distancia es menor a 20cm el ruido sera mas agudo que si la distancia esta entre mayor a 20 y menor a 40
    tone(8, 500, 100);
  }else if(distance>20 && distance<40){
    tone(8, 200, 100);
  }
  }
}


// Funcion que calcula la distancia real con los datos que nos devuelve el sensor ultrasonico
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}
