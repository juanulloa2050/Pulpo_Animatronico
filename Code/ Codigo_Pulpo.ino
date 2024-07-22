//Librerias
#include "DFRobotDFPlayerMini.h"
#include "LedControl.h" // Libreria para controlar Matriz

//Configuracion del audio/////////////////////////////////////////////

// Create the Player object
int estado="s";

//Motores
int motor1=11;
int motor2=12;
int motor3=10;
int motor4=9;

/*PLANO PARA EL MONTAJE de los ojos /////////////////////////////////////////
Pines: 7 = DIN  5 =CLK  4 = CS 
5V - GND 
*/

LedControl lc=LedControl(7, 5, 6, 1); //Pines + 2 dado a que son 2 Pantallas
#define demora 200 
byte neutro[8] = {B00111100,B01111110,B11111111,B11100111,B11100111,B11111111,B01111110,B00111100};
byte abajo[8]={B00111100,B01111110,B11111111,B10011111,B10011111,B11111111,B01111110,B00111100};
byte arriba[8]={B00111100,B01111110,B11111111,B11111001,B11111001,B11111111,B01111110,B00111100};
byte izquierda[8]={B00111100,B01100110,B11100111,B11111111,B11111111,B11111111,B01111110,B00111100};
byte derecha[8]={B00111100,B01111110,B11111111,B11111111,B11111111,B11100111,B01100110,B00111100};
byte mimir[8]={B00011000,B00111000,B01110000,B11100000,B11100000,B01110000,B00111000,B00011000};
byte linea[8]={B00011000,B00011000,B00011000,B00011000,B00011000,B00011000,B00011000,B00011000};
byte muerto[8]={B11000011,B11100111,B01111110,B00111100,B00111100,B01111110,B11100111,B11000011};
byte off[8]={B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
///////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin (9600);

  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);

  //Matriz 1  
  lc.shutdown(0,false);       // enciende la matriz
  lc.setIntensity(0,4);       // establece brillo
  lc.clearDisplay(0);         // Se limpia la matriz
//Matriz 2 
  lc.shutdown(1,false);       // enciende la matriz
  lc.setIntensity(1,4);       // establece brillo
  lc.clearDisplay(1);         // Se limpia la matriz
}
void loop() {
  if(Serial.available()>0){        // lee el mensaje enviado desde la APP bluetooth y almacena en variable estado
  estado = Serial.read();  
  if (estado =='v'){
   }
   else if (estado =='a'){
       mostrar_ojo_arri (); 
       delay(demora);
   }
   else if (estado =='2'){
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW); //atras
    digitalWrite(motor4, HIGH);
    delay(2000);
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
   }
   else if (estado =='1'){
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH); //adelante
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
    delay(1500);
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
   }
   else if (estado =='r'){
       mostrar_ojo_abajo (); 
       delay(demora);
   }
   else if (estado =='i'){
       mostrar_ojo_iz (); 
       delay(demora); 
   }
   else if (estado =='d'){
       mostrar_ojo_der (); 
       delay(demora);
   }
   else if (estado =='t'){
      a_mimir();
      delay(demora);
   }
   else if (estado =='s'){
      mostrar_ojo_centro (); 
      delay(demora);
   }
   else if(estado =='h'){
    serio();
    delay(demora); 
   }
   }
  }
//FUNCIONES PARA LOS OJOS////////////////////////////////////////////////////////////////////////////////////
void mostrar_ojo_centro() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,neutro[i]);//Matriz 1 
    lc.setRow(1,i,neutro[i]);//Matriz 2
  }
}
void mostrar_ojo_abajo() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,abajo[i]);//Matriz 1 
    lc.setRow(1,i,abajo[i]);//Matriz 2
  }
  }
void mostrar_ojo_arri() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,arriba[i]);//Matriz 1 
    lc.setRow(1,i,arriba[i]);//Matriz 2
  }
}
void mostrar_ojo_iz() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,izquierda[i]);//Matriz 1 
    lc.setRow(1,i,izquierda[i]);//Matriz 2
  }
}
void mostrar_ojo_der() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,derecha[i]);//Matriz 1 
    lc.setRow(1,i,derecha[i]);//Matriz 2
  }
}
void a_mimir() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,mimir[i]);//Matriz 1 
    lc.setRow(1,i,mimir[i]);//Matriz 2
  }
}
void serio() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,linea[i]);//Matriz 1 
    lc.setRow(1,i,linea[i]);//Matriz 2
  }
}
void KO() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,muerto[i]);//Matriz 1 
    lc.setRow(1,i,muerto[i]);//Matriz 2
  }
}
void parpadear() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,off[i]);//Matriz 1 
    lc.setRow(1,i,off[i]);//Matriz 2
  }
}
