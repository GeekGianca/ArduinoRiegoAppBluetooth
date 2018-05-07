#include <SoftwareSerial.h>

SoftwareSerial ModBluetooth(2, 3); // RX | TX
int relay = 12;

void setup()
{
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  pinMode(relay, OUTPUT);
  ModBluetooth.begin(9600);
  Serial.begin(9600);
  ModBluetooth.println("Modulo Conectado");
  ModBluetooth.print("#");
}


void loop()
{
  if (ModBluetooth.available())
  {
    char VarChar;

    VarChar = ModBluetooth.read();

    if (VarChar == '1')
    {
      digitalWrite(13, HIGH);
      digitalWrite(relay, LOW);
      delay(100);
      ModBluetooth.print("Riego Encendido");
      Serial.println("Riego Encendido");
      ModBluetooth.print("#");
    }
    if (VarChar == '0')
    {
      digitalWrite(13, LOW);
      digitalWrite(relay, HIGH);
      delay(100);
      ModBluetooth.print("Riego Apagado#");
      Serial.println("Riego Apagado#");
    }
  }
}
