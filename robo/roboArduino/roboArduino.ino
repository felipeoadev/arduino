// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

//Define os motores do shield que serão usados
AF_DCMotor motorDir(1), motorEsq(2);

//`Portas Analogicas do Sensor de refletancia
int sensorLinhaDir = A0;
int sensorLinhaEsq = A1;

//Valor de corte < 700 branco > preto
int ValorCorte = 700;

//Velocidade do carrinho
const int velocidade = 180;

//Valores de leitura do sensor de refletancia
int valorLinhaEsq, valorLinhaDir = 0;

void setup() 
{
  Serial.begin(9600);           // set up Serial library at 9600 bps

  //Liga is motores
  motorDir.setSpeed(velocidade);
  motorEsq.setSpeed(velocidade); 

  //motorDir.run(RELEASE);
  //motorEsq.run(RELEASE);
}

void loop() 
{
  uint8_t i;
  
  valorLinhaEsq = analogRead(sensorLinhaEsq);    
  valorLinhaDir = analogRead(sensorLinhaDir); 
  
  //Se os sensores maior que valor de corte segue em frente 
  if((valorLinhaEsq > ValorCorte) && (valorLinhaDir > ValorCorte))
  {
    motorDir.run(BACKWARD);
    motorEsq.run(BACKWARD);
    
    motorDir.run(FORWARD);
    motorEsq.run(BACKWARD);    
  }  
  
  //Se os sensores esquerdo menor que valor de corte vira para esquerda
  if((valorLinhaEsq < ValorCorte)&&(valorLinhaDir > ValorCorte))
  {
    //motorEsq.setSpeed(velocidade);
    
    motorDir.run(RELEASE);
    motorEsq.run(FORWARD);
  }  

  //Se os sensor direito menor que valor de corte vira para esquerda 
  if((valorLinhaEsq > ValorCorte)&&(valorLinhaDir < ValorCorte))
  {
    //motorDir.setSpeed(velocidade);
    //motorEsq.setSpeed(0);
    
    motorDir.run(FORWARD);
    motorEsq.run(RELEASE);
  }
 
  Serial.print("Sensor 1 ");
  Serial.println(valorLinhaEsq);
  
  
   Serial.print("Sensor 2 ");
  Serial.println(valorLinhaDir);
 
  delay(250);    
}
