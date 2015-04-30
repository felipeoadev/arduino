// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

//Define os motores do shield que serão usados
AF_DCMotor motorDir(1), motorEsq(2);

//`Portas Analogicas do Sensor de refletancia
int sensorLinhaDir = A8;
int sensorLinhaEsq = A9;

//Valor de corte < 700 branco > preto
int ValorCorte = 700;

//Velocidade do carrinho
const int velocidade = 200;

//Valores de leitura do sensor de refletancia
int valorLinhaEsq, valorLinhaDir = 0;

void setup() 
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  //Liga is motores
  motorDir.setSpeed(velocidade);
  motorEsq.setSpeed(velocidade);
 
  motorDir.run(RELEASE);
  motorEsq.run(RELEASE);
}

void loop() 
{
  uint8_t i;
  
  valorLinhaEsq = analogRead(sensorLinhaEsq);    
  valorLinhaDir = analogRead(sensorLinhaDir);
  
  if((valorLinhaEsq > ValorCorte)&&(valorLinhaDir > ValorCorte))
  {
    motorDir.setSpeed(velocidade);
    motorEsq.setSpeed(velocidade);
 
    motorDir.run(FORWARD);
    motorEsq.run(FORWARD);
  }  
  
  if((valorLinhaEsq < ValorCorte)&&(valorLinhaDir > ValorCorte))
  {
    motorDir.setSpeed(velocidade);
    motorEsq.setSpeed(velocidade);
    
    motorDir.run(FORWARD);
    motorEsq.run(BACKWARD);     
  }  
 
  if((valorLinhaEsq > ValorCorte)&&(valorLinhaDir < ValorCorte))
  {
    motorDir.setSpeed(velocidade);
    motorEsq.setSpeed(velocidade);
    
    motorDir.run(BACKWARD);
    motorEsq.run(FORWARD);        
  }
  
  Serial.println("Linha Esq: ");
  Serial.println(valorLinhaEsq);
  Serial.println("   Linha Dir: ");
  Serial.println(valorLinhaDir);
  
  delay(250);  
  
  
}
