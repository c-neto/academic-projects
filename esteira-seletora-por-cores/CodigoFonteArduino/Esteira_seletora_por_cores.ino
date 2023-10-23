// PROGRAMAÇÃO EM TESTES

#include <Servo.h>             //Biblioteca do servo
#include <LiquidCrystal_I2C.h> //Biblioteca do display
#include <Wire.h>              //Outra parte da biblioteca do display
#include "Ultrasonic.h"        //Biblioteca do Ultrasonico

//BOTAO PARA ZERAR CONTAGEM
const int botao = 3;           //Porta do Botão
int est = 0;           //Estado do Botão

Servo motor_unico;             //Incluindo Servo na Programação

int sinalparaorele = 13;       //Porta do Relê    

//PINOS DO ULTRASONICO
Ultrasonic ultrasonic(6,7);    //Criando objeto ultrasonic e definindo as portas digitais do Trigger ->6, Echo ->7
long microsec = 0;             //Calcula o tempo das ondas ultrassônicas
float distanciaCM = 0;         //Armazena a distância em centimetros

//Pinos de conexao do modulo TCS230  
const int s0 = 8;  
const int s1 = 9;  
const int s2 = 12;  
const int s3 = 11;  
const int out = 10;   
   
    
//Variaveis que armazenam o valor das cores  
int red = 0;  
int green = 0;  
int blue = 0;  
 
// definir o endereço de LCD de 0x27 para um display de 16 caracteres e 2 linhas
LiquidCrystal_I2C lcd(0x27,16,2); 
int contadorver = 0; 
int contadorazul = 0; 
int contadorverd = 0; 
 
    
void setup(){
  Serial.begin(9600);  
  motor_unico.attach(5);   //PORTA DO SERVO
  pinMode(botao,INPUT);            //Declara que o "botão" é uma entrada de informação
  pinMode(sinalparaorele, OUTPUT); //Declara que o Rele é uma saida de informação
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  

  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  
}  
    
void loop() {  
  
//////// MOSTRA NO SERIAL MONITOR O VALOR DAS INTENSIDADES DETECTADAS PELO SENSOR RGB ///////
 
  color(); //Chama a rotina que le as cores  
 
  //Mostra no serial monitor os valores detectados  
  Serial.print("Vermelho :");  
  Serial.print(red, DEC);  
  Serial.print(" Verde : ");  
  Serial.print(green, DEC);  
  Serial.print(" Azul : ");  
  Serial.print(blue, DEC);
   
  Serial.println();  
  
        
   ///////////////////// BOTÃO ////////////////
  est = digitalRead(botao);  
    

  if (est == HIGH) {
    
  contadorver = 0; 
  contadorazul = 0; 
  contadorverd = 0; 
    
  lcd.init(); 
  lcd.backlight(); 
  lcd.print("CONTADOR");
  lcd.setCursor (0,1);
  lcd.print("REINICIADO");
}

//////////////////// ULTRASSÔNICO //////////
 
  //Lendo o sensor
  microsec = ultrasonic.timing(); 
 
  //Convertendo a distância em CM
  distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM); 

  Serial.print(distanciaCM);
  Serial.println(" cm");
  
//////////////// ACIONANDO O RELÊ /////////////

  digitalWrite(sinalparaorele, LOW); //Relê ligado
    
  if (distanciaCM <= 5) {
    digitalWrite(sinalparaorele, HIGH); //Desliga o Relê
  }
  
//////////////// POSIÇÃO DE INICIO /////////////
  motor_unico.write(90);
  Serial.println();
  lcd.init(); 
  lcd.backlight(); 
  lcd.print("    INICIO");
  
  lcd.setCursor (0,1);
  
  lcd.print("R:");
  lcd.print(contadorver);
  
  lcd.print("   G:");
  lcd.print(contadorverd);
  
  lcd.print("   B:");
  lcd.print(contadorazul);
 
/////////////////// VERMELHA //////////////////
 
  if (green>blue && blue>red && red<35){  //Verifica se a cor VERMELHA foi detectada 
    Serial.println("Vermelho");  
    motor_unico.write(0);  
    digitalWrite(sinalparaorele, LOW); //Liga o Relê
  
    contadorver++;
    lcd.init(); 
    lcd.backlight(); 
    lcd.print("VERMELHO");
    lcd.setCursor (0,1);
    lcd.print("CONTAGEM: ");
    lcd.print(contadorver);
    delay (2000);
  }  

////////////////// AZUL //////////////////////

  else if (blue < red && blue < green && blue > 5){   //Verifica se a cor AZUL foi detectada  
    
    Serial.println("Azul");  
    motor_unico.write(100);
    digitalWrite(sinalparaorele, LOW); //Liga o Relê

    contadorazul++;
    lcd.init(); 
    lcd.backlight(); 
    lcd.print("AZUL");
    lcd.setCursor (0,1);
    lcd.print("CONTAGEM: ");
    lcd.print(contadorazul);
    delay (2000);

  }  

////////////// VERDE //////////////

  else if (red<30 && green<30 && blue<30 && blue>green && blue>red){  //Verifica se a cor VERDE foi detectada    
    Serial.println("Verde");  
    motor_unico.write(180);
    digitalWrite(sinalparaorele, LOW); //Liga o Relê
    contadorverd++;
    lcd.init(); 
    lcd.backlight(); 
    lcd.print("VERDE");
    lcd.setCursor (0,1);
    lcd.print("CONTAGEM: ");
    lcd.print(contadorverd);
    delay (2000);
  } 
  
//////// COR NÃO IDENTIFICADA////////////

  else if (red>45 && red<50 && blue>65 && blue<75 && green>65 && green<75){  
    Serial.println("XXX");  
    motor_unico.write(90);
    lcd.init(); 
    lcd.backlight(); 
    lcd.print(" COR"); 
    lcd.setCursor (0,1);
    lcd.print("NAO IDENTIFICADA");
    delay (2000);  //Aguarda 2 segundos, apaga os leds e reinicia o processo  
  }
  Serial.println();  
}  
 
    
void color()  
{  
  //Rotina que le o valor das cores  
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}

