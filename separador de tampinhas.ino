#include <Servo.h> // inclui a biblioteca servo.h
#define pinServo 7 // define o pino 7 como o de comando do servo motor
#define S0 8 // Atribui ao pino 8 o nome de SO, referente ao pino SO do sensor de cor
#define S1 9 // Atribui ao pino 9 o nome de S1, referente ao pino S1 do sensor de cor
#define S2 12 // Atribui ao pino 12 o nome de S2, referente ao pino S2 do sensor de cor
#define S3 11 // Atribui ao pino 11 o nome de S3, referente ao pino S3 do sensor de cor
#define OutSensor 10 // Atribui ao pino 10 o nome de OutSensor, referente ao pino OUT do sensor de cor
 
int red = 0; // declara uma variavel int de nome red_frequency
int green = 0; // declara uma variavel int de nome green_frequency
int blue = 0;// declara uma variavel int de nome blue_frequency
int temp = 10000;
int anguloc = 120;
int anguloer = 50;
Servo servo; // declara uma variavel de nome servo na biblioteca Servo.h
  
void setup(){
  pinMode(S0, OUTPUT); // define o pino denominado SO como saída 
  pinMode(S1, OUTPUT); // define o pino denominado S1 como saída 
  pinMode(S2, OUTPUT); // define o pino denominado S2 como saída 
  pinMode(S3, OUTPUT); // define o pino denominado S3 como saída 
  pinMode(OutSensor, INPUT); // define o pino denominado OutSensor como saída 
  Serial.begin(9600); // Inicia a comunicação serial
  digitalWrite(S0, HIGH); // configura a escala de frequência do sensor para 20%
  digitalWrite(S1, LOW); // configura a escala de frequência do sensor para 20%
  servo.attach(pinServo); // inicia a comunicação com o servo motor
}
  
void loop(){
 
// leitura da cor vermelha
digitalWrite(S2,LOW); // configuração para os Fotodiodos red serem lidos
digitalWrite(S3,LOW); // configuração para os Fotodiodos red serem lidos
red = pulseIn (OutSensor, LOW); // armazena na variável red a frequência lida em OutSensor
Serial.print ("R= "); // escreve a letra R no monitor serial
Serial.print (red); // apresenta os valores armazenados na variável red no monitor serial
Serial.print ("   "); // espaço de texto no monitor serial
 
// leitura da cor verde
digitalWrite(S2,HIGH); // configuração para os Fotodiodos green serem lidos
digitalWrite(S3,HIGH); // configuração para os Fotodiodos green serem lidos
green = pulseIn (OutSensor, LOW); // armazenya na variável green a frequência lida em OutSensor
Serial.print ("G= "); // escreve a letra G no monitor serial
Serial.print (green); // apresenta os valores armazenados na variável green no monitor serial
Serial.print ("   "); // espaço de texto no monitor serial
 
// leitura da cor azul
digitalWrite(S2,LOW); // configuração para os Fotodiodos blue serem lidos
digitalWrite(S3,HIGH); // configuração para os Fotodiodos blue serem lidos
blue = pulseIn (OutSensor, LOW); // armazena na variável blue a frequência lida em OutSensor
Serial.print ("B= "); // escreve a letra B no monitor serial
Serial.print (blue); // apresenta os valores armazenados na variável blue no monitor serial
Serial.print ("   "); // espaço de texto no monitor serial
   
  // condiçoes para detecção das cores e atuação do servo motor
  if (190 < red && red < 420 &&  420 < green  && green  < 590 && 330 < blue && blue < 480){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Vermelho"); 
    servo.write(anguloc);
    delay(temp);}
  else if (550 < red && red < 700 && 480 < green && green < 580 && 230 < blue && blue < 390){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Azul");
    servo.write(anguloc);
    delay(temp);}
  else if (150 < red && red < 360 && 200  < green && green < 320 && 250 < blue && blue < 380){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Verde");
    servo.write(anguloc);
    delay(temp);}
  else if (100 < red && red < 200 &&  110 < green && green < 270 && 210 < blue && blue < 390){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Amarelo");
    servo.write(anguloc);
    delay(temp);}
  else if (290 < red && red < 400 &&  290 < green && green < 490 && 200 < blue && blue < 350){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Branco");
    servo.write(anguloc);
    delay(temp);}
  else {
    servo.write(anguloer);
  }
 Serial.println();
 delay(300);
}


  



  
