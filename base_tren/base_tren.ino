// demo of Starter kit V2.0 - Grove - Light Sensor
// when the value of light sensor ledd than a certain value
// led will on, you can set this certain value via change thresholdvalue
// such as when you cover light sensor with your hand, you'll find led on
#include <Arduino.h>
#include <NECIRrcv.h>
#define IRPIN 4 
const int pinLight = A2;
const int pinLed   = 7;

int thresholdvalue=400;                 //the threshold to turn on or off the LED

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
const int buttonPin = 5;     // the number of the pushbutton pin
const int ledPin =  6;      // the number of the LED pin
const int alto=2;
const int siga=3;
int cont=0;
// variables will change:
int buttonState = 0;   
  // pin that IR detector is connected to

static int aux = 1;
NECIRrcv ir(IRPIN) ;

 
void setup()
{
    pinMode(pinLed, OUTPUT);             //set the LED on Digital 12 as an OUTPUT
     lcd.begin(16, 2);

    // Print a message to the LCD.
    lcd.print("Bienvenido ...");
    pinMode(ledPin, OUTPUT);
    pinMode(alto,OUTPUT);
    pinMode(siga,OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
    Serial.begin(9600);
   //   pinMode(led, OUTPUT);
  ir.begin() ;
    delay(1000);
}

void loop()
{
  // lcd.clear();
   luz(); 
   ird();
   if (cont==0) 
   {
   avanzar();
   }
   if (cont != 0)
   {
    cont = cont - 1;
    Serial.println(cont);
   }
   delay(300);
}
void luz()
{
  int sensorValue = analogRead(pinLight);    //the light sensor is attached to analog 0
    if(sensorValue<thresholdvalue)
    {
        digitalWrite(pinLed, HIGH);
        lcd.setCursor(0, 1);
        lcd.print("Luz encendida...");
        
    }
    else
    {
        digitalWrite(pinLed, LOW);
        lcd.setCursor(0, 1);
        lcd.print("Luz Apagada...  ");
    }
}
void avanzar()
{
   // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(alto,LOW);
    digitalWrite(siga,HIGH);
     lcd.setCursor(0, 0);
    lcd.print("Tren Avanzando  ");
    digitalWrite(ledPin, HIGH);
    cont=100;
  } else {
    // turn LED off:
    digitalWrite(alto,HIGH);
    digitalWrite(siga,LOW);
    lcd.setCursor(0, 0);
    lcd.print("Tren Detenido  ");
    digitalWrite(ledPin, LOW);
  }
}
void ird()
{
  unsigned long ircode ;
  while (ir.available()) { 
    ircode = ir.read() ;
    if(ircode == 3125149440){  /*en nuestro caso, corresponde con el botón encendido/apagado del mando*/
      if(aux == 0){
        cont=100;
    digitalWrite(alto,LOW);
    digitalWrite(siga,HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Tren Avanzando  ");
    digitalWrite(ledPin, HIGH);
        aux = 1;
      }
      else{
        
        aux = 0;
      }
    } 
  }
}




