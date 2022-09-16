//elevador proyecto 
#include <SoftwareSerial.h> // TX RX 
//Variables motor 1 driver
int IN1=10; //adelante
int IN2=11; //atras
int boton1=6; // planta baja, ir hacia arriba
int val1=0; // variable de estado de boton
int boton2=7; // planta 2, ir hacia abajo
int val2=0; // variable de estado de boton
int boton3=8; // planta 2, ir hacia arriba
int val3=0; // variable de estado de boton
int boton4=9; // planta 3, ir hacia abajo
int val4=0; // variable de estado de boton
int led1=5; // led planta baja
int led2=4; // led piso 2 abajo
int led3=3; // led piso 2 arriba
int led4=2; // led piso 3, abajo
//int poss=1; // posicion del elevador

void setup()
{
Serial.begin(9600);
pinMode(IN1,OUTPUT); //Definimos cada pin como una salida
pinMode(IN2,OUTPUT); //Definimos cada pin como una salida
pinMode(boton1,INPUT); //Definimos cada pin como una ENTRADA
pinMode(boton2,INPUT); //Definimos cada pin como una ENTRADA
pinMode(boton3,INPUT); //Definimos cada pin como una ENTRADA
pinMode(boton4,INPUT); //Definimos cada pin como una ENTRADA
pinMode(led1,OUTPUT); //Definimos cada pin como una salida
pinMode(led2,OUTPUT); //Definimos cada pin como una salida
pinMode(led3,OUTPUT); //Definimos cada pin como una salida
pinMode(led4,OUTPUT); //Definimos cada pin como una salida
val1=LOW;
val2=LOW;
val3=LOW;


}

void loop()   //  
{

   val1=digitalRead(6); //lee el estado del pin 2 asignado para la planta primera
   //Serial.println(val1,"plantabaja");
   val2=digitalRead(7); //lee el estado del pin 3 asignado para la planta segunda
   //Serial.println(val2,"segundo piso");
   val4=digitalRead(9); //lee el estado del pin 4 asignado para la planta tercera
   //Serial.println(val4,"tercer piso");
   int poss=1; // posicion del elevador
   if(val2==HIGH) // SEGUNDO PISO
   {
     Serial.println("segundo piso select");
     if(poss==1)
      {
        Serial.println("si esta en pb");
        digitalWrite(led2,HIGH); //se enciende led de planta baja
        digitalWrite(IN1,LOW); //bajar polea
        digitalWrite(IN2,HIGH); //subir polea 
        delay(2000); // led y motor funcionando por 5 segundos
        digitalWrite(led2,LOW); //se enciende led de planta baja
        digitalWrite(IN1,LOW); //bajar polea
        digitalWrite(IN2,LOW); //subir polea 
        poss=poss +1; // ubicacion de elevador
        val1=LOW;
        val2=LOW;
        val3=LOW;
        }
     if(poss==3)
    {
    digitalWrite(led2,HIGH); //se enciende led de planta baja
    digitalWrite(IN1,HIGH); //bajar polea
    digitalWrite(IN2,LOW); //subir polea 
    delay(2000); // led y motor funcionando por 5 segundos
    digitalWrite(led2,LOW); //se enciende led de planta baja
    digitalWrite(IN1,LOW); //bajar polea
    digitalWrite(IN2,LOW); //subir polea
    poss=poss-1; // ubicacion de elevador
    val1=LOW;
    val2=LOW;
    val3=LOW;
    }
   }
    else if(val4==HIGH) // TERCER PISO
{
    if(poss==1)
    {
    digitalWrite(led3,HIGH); //se enciende led de planta baja
    digitalWrite(IN1,LOW); //bajar polea
    digitalWrite(IN2,HIGH); //subir polea 
    delay(2000); // led y motor funcionando por 5 segundos
    digitalWrite(led3,LOW); //se enciende led de planta baja
    digitalWrite(IN1,LOW); //bajar polea
    digitalWrite(IN2,LOW); //subir polea
    poss=poss+2; // ubicacion de elevador
    val1=LOW;
    val2=LOW;
    val3=LOW;
    }
      if(poss==2)
    {
    digitalWrite(led3,HIGH); //se enciende led de planta baja
    digitalWrite(IN1,LOW); //bajar polea
    digitalWrite(IN2,HIGH); //subir polea 
    delay(2000); // led y motor funcionando por 5 segundos
    digitalWrite(led3,LOW); //se enciende led de planta baja
    digitalWrite(IN1,LOW); //bajar polea
    digitalWrite(IN2,LOW); //subir polea
    poss=poss+1; // ubicacion de elevador
    val1=LOW;
    val2=LOW;
    val3=LOW;
    }
}
else if(val1==HIGH) // PLANTA BAJA
{
  if(poss==2)
  {
  digitalWrite(led1,HIGH); //se enciende led de planta baja
  digitalWrite(IN1,HIGH); //bajar polea
  digitalWrite(IN2,LOW); //subir polea 
  delay(2000); // led y motor funcionando por 5 segundos
  digitalWrite(led1,LOW); //se enciende led de planta baja
  digitalWrite(IN1,LOW); //bajar polea
  digitalWrite(IN2,LOW); //subir polea
  poss=poss-1; // ubicacion de elevador
  val1=LOW;
  val2=LOW;
  val3=LOW;
  
  }
    if(poss==3)
  {
  digitalWrite(led1,HIGH); //se enciende led de planta baja
  digitalWrite(IN1,HIGH); //bajar polea
  digitalWrite(IN2,LOW); //subir polea 
  delay(2000); // led y motor funcionando por 5 segundos
  digitalWrite(led1,LOW); //se enciende led de planta baja
  digitalWrite(IN1,LOW); //bajar polea
  digitalWrite(IN2,LOW); //subir polea
  poss=poss-2; // ubicacion de elevador
  val1=LOW;
  val2=LOW;
  val3=LOW;
  }
}

}
