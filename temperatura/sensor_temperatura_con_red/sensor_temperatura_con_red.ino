#include <DHT11.h> // biblioteca sensor temperatura
#include <Wire.h> 
#include "rgb_lcd.h" //biblioteca de la pantalla lcd rgb
#include <Ethernet.h> //biblioteca del shield ethernet
#include <SPI.h>


rgb_lcd lcd; 

const int colorR = 255; //en este bloque se definen lo colores de la pantalla
const int colorG = 255;
const int colorB = 255;

int pin=7; // se define el pin que utilizara el sensor como entrada
DHT11 dht11(pin);

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFF, 0xEE}; // Direccion MAC
byte ip[] = { 192,168,0,220 }; // Direccion IP del Arduino
byte server[] = { 192,168,0,137}; // Direccion IP del servidor que contiene la base mysql
EthernetClient client; 
float temperatura; //variable de la temperatura, flotante para manejo de numeros decimales
int analog_pin = 0;
String lugar = "Arica";

void setup()
   {
       Serial.begin(9600);
       Ethernet.begin(mac, ip); // Inicializamos el Ethernet Shield
       delay(1000); // Esperamos 1 segundo de cortesia
   }

void loop()
   {
       int err;
       float temp, hum;
       if((err = dht11.read(hum, temp)) == 0)    // Si devuelve 0 es que ha leido bien
          {
             //inicializa el visor y asigna los parametros que mostrara
             lcd.begin(16, 2); 
             lcd.setRGB(colorR, colorG, colorB);
             lcd.print("Temp. : ");
             lcd.print(temp);
             lcd.setCursor(0, 1);
             lcd.print(" Humedad: ");
             lcd.print(hum);          

             //inicializa el monitor serial de arduino
             Serial.print("Temperatura: ");
             Serial.print(temp);
             Serial.print(" Humedad: ");
             Serial.print(hum);
             Serial.println();
          }
       else
          {
             //caotura y muestra el error
             Serial.println();
             Serial.print("Error Num :");
             Serial.print(err);
             Serial.println();
          }
   
        if (client.connect(server, 80)>0)
                {  // Conexion con el servidor y envia los datos
                   // client.print("GET /project/arduino/temperatura/iot.php?valor="); // Enviamos los datos por GET
                    client.print("GET /temperatura/iot.php?valor=");
                    // & lugar="[lugar]); // Enviamos los datos por GET
                    client.print(temp);
                    client.print("GET /temperatura/iot.php?hum=");
                    //client.print("GET /temperatura/iot.php?hum="); // Enviamos los datos por GET
                    client.print(hum);
                    //client.print("GET /temperatura/iot.php?lugar="); // Enviamos los datos por GET
                    //client.print(lugar);
                    
                    client.println(" HTTP/1.0");
                    client.println("User-Agent: Arduino 1.0");
                    client.println();
                    Serial.println("Conectado");
                 }
        else
                 {
                    Serial.println("Fallo en la conexion");
                 }
        if (!client.connected())
                 {
                    Serial.println("Disconnected!");
                 }
               client.stop();
               client.flush();
               delay(500); // Espero un minuto antes de tomar otra muestra
                          
       // delay(1000);            //Recordad que solo lee una vez por segundo
   }    

