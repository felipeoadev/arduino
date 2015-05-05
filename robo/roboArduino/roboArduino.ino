// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <Wire.h>
#include <AFMotor.h>

//Define os motores do shield que serão usados
AF_DCMotor motorDir(1), motorEsq(2);

#define M1_DEFAULT_SPEED 75
#define M4_DEFAULT_SPEED 75
#define M1_MAX_SPEED 130
#define M4_MAX_SPEED 130

//`Portas Analogicas do Sensor de refletancia
int sensorLinhaDir = A8;
int sensorLinhaEsq = A9;

//Valor de corte < 700 branco > preto
int ValorCorte = 700;

//Velocidade do carrinho
//const int velocidade = 150;

//Valores de leitura do sensor de refletancia
int valorLinhaEsq, valorLinhaDir = 0;

void setup() 
{
  Serial.begin(9600);           // set up Serial library at 9600 bps

  //Liga is motores
  motorDir.setSpeed(M1_MAX_SPEED);
  motorEsq.setSpeed(M1_MAX_SPEED); 

  motorDir.run(RELEASE);
  motorEsq.run(RELEASE);
}

void loop() 
{
  uint8_t i;
  
  valorLinhaEsq = analogRead(sensorLinhaEsq);    
  valorLinhaDir = analogRead(sensorLinhaDir); 
  
  //Se os sensores maior que valor de corte segue em frente 
  if((valorLinhaEsq > ValorCorte) && (valorLinhaDir > ValorCorte))
  {
    motorDir.run(FORWARD);
    motorEsq.run(FORWARD);

    motorDir.setSpeed(M1_MAX_SPEED);
    motorEsq.setSpeed(M1_MAX_SPEED);
  }  
  
  //Se os sensores esquerdo menor que valor de corte vira para esquerda
  if((valorLinhaEsq < ValorCorte)&&(valorLinhaDir > ValorCorte))
  {
    //motorDir.setSpeed(velocidade);
    //motorEsq.setSpeed(velocidade);
    
    motorDir.run(FORWARD);
    motorEsq.run(RELEASE);      
    motorDir.setSpeed(M4_DEFAULT_SPEED);    
  }  

  //Se os sensor direito menor que valor de corte vira para esquerda 
  if((valorLinhaEsq > ValorCorte)&&(valorLinhaDir < ValorCorte))
  {
    //motorDir.setSpeed(velocidade);
    //motorEsq.setSpeed(velocidade);
    
    motorDir.run(RELEASE);
    motorEsq.run(FORWARD);
    motorEsq.setSpeed(M4_DEFAULT_SPEED);        
  }
  
  delay(250);    
}
