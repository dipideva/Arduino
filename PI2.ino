#include <SoftwareSerial.h>

SoftwareSerial serialdobluetooth(8,9); // Portas do (RX e TX).
int valordobluetooth;
const int LM35 = A0;
int pin = 0;
float temperatura;
int tempc = 0; 
int i = 1;
unsigned long temporizador = millis();
unsigned long temporizador2 = millis();
unsigned long temporizador3 = millis();

void setup() {
Serial.begin(9600);
pinMode(7,OUTPUT);

}
 
void loop() {

  bluetooth();
  medeTemp();
} 

void bluetooth(){
if (serialdobluetooth.available()) {
  valordobluetooth = serialdobluetooth.read();
}  

  
}

void jogaAgua(){
  
  if((millis() - temporizador) < 2000){
    digitalWrite(7,HIGH);
  }else{
    digitalWrite(7,LOW);
  }
  if((millis() - temporizador) > 5000){
    temporizador = millis();
  }
}
void medeTemp(){
  if((millis() - temporizador2) < 10){
      for(i = 0;i<=8;i++){ //Loop que faz a leitura da temperatura 8 vezes
        if((millis() - temporizador3) < 100){
          tempc = (float(analogRead(pin))*5/(1023))/0.01;
          Serial.print("Temperatura: ");
          Serial.println(tempc);
          
        }
        if((millis() - temporizador3) > 200){
          temporizador3 = millis();
        }  
  }
    

  }
  if((millis() - temporizador2) > 1000){
    temporizador2 = millis();
  }
}