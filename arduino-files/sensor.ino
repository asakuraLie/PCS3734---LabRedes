//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
//Autor: MakerHero
 
//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 6
#define pino_echo 7
#define led 4
#define relay 5
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  Serial.begin(9600);
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
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);

  if(cmMsec < 10){
    digitalWrite(led, HIGH);
    digitalWrite(relay, LOW);
  }
  else {
    digitalWrite(led, LOW);
    digitalWrite(relay, HIGH);
  }
  
  delay(1000);
}