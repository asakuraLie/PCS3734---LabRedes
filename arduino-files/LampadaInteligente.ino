//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
//Autor: MakerHero
 
//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
#include <SoftwareSerial.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 6
#define pino_echo 7
#define led 5
#define relay 13
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
SoftwareSerial bluetooth(11, 12);
char incomingValue = 0;
 
void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("Lendo dados do sensor...");
  pinMode(led, OUTPUT); 
  pinMode(relay, OUTPUT); 
}
 
void loop()
{
  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  // Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);

  // Le as informacoes do bluetooth
  incomingValue = bluetooth.read();
  delay (10);

  if(incomingValue == '1'){
    do {
        digitalWrite(led, HIGH);
        digitalWrite(relay, LOW);
        incomingValue = bluetooth.read();
        delay(10);
    } while (incomingValue != '0');
  } else if (cmMsec < 10) {
    digitalWrite(led, HIGH);
    digitalWrite(relay, LOW);
  } else if (cmMsec >= 10) {
    digitalWrite(led, LOW);
    digitalWrite(relay, HIGH);
  }
  
  delay(1000);
}
