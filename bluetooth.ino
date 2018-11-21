//Programma per alimentare un pin a distanza 

#include <SoftwareSerial.h>   //Per include la libreria che trasforma le porte digitali in porte TX & RX

//Dichiarazione pin TX & RX

int rxPin = 3;   //Bisgna Collegarlo all'uscita TX del modulo bluetooth
int txPin = 2;   //Bisogna colegarlo all'uscita RX del modulo bluetooth
SoftwareSerial bluetooth(rxPin, txPin);

const int Rele = 13;   //Dichiarazione pin da alimentare
int state = 76;

void setup()
{
  Serial.begin(9600);   //Imposta la velocità di trasmissione
  bluetooth.begin(9600);   //Imposta la velocità di trasmissione
  pinMode(Rele,OUTPUT);
  digitalWrite(Rele, HIGH);
}

void loop()
{
  while(bluetooth.available())
  {
    state = bluetooth.read();
    if(state == 76)
      {
          digitalWrite(Rele, HIGH);
          Serial.println("Rele ON");   //Attiva il pin 
          delay(200);
       }
       else if(state == 72)
       {
          digitalWrite(Rele, LOW);
          Serial.println("Rele OFF");   //Disattiva il pin
          delay(200);
       }
  }
}
