// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

//Define os motores do shield que serão usados
AF_DCMotor motorDir(1), motorEsq(2);

//`Portas Analogicas do Sensor de refletancia
int sensorLinhaEsq = 8;
int sensorLinhaDir = 9;

//Valor de corte < 700 branco > preto
int ValorCorteEsq = 900;
int ValorCorteDir = 700;

//Velocidade do carrinho
const int velocidade = 130;

//Valores de leitura do sensor de refletancia
int valorLinhaEsq, valorLinhaDir = 0;

void setup() 
{
  Serial.begin(9600);           // set up Serial library at 9600 bps

  //Liga is motores
  motorDir.setSpeed(velocidade);
  motorEsq.setSpeed(velocidade); 

  //motorDir.run(RELEASE)
  //motorEsq.run(RELEASE);
}

void loop() 
{
  uint8_t i;
  
  valorLinhaEsq = analogRead(sensorLinhaEsq);    
  valorLinhaDir = analogRead(sensorLinhaDir); 
  
  Serial.print("Esquerda ");
  Serial.println(valorLinhaEsq);
  
    Serial.print("Direita ");
  Serial.println(valorLinhaDir);

  
  //Se os sensores maior que valor de corte segue em frente 
  if((valorLinhaEsq > ValorCorteEsq) && (valorLinhaDir > ValorCorteDir))
  {
    motorDir.run(FORWARD);
    motorEsq.run(FORWARD);    
  }  
  
  //Se os sensores esquerdo menor que valor de corte vira para esquerda
  if((valorLinhaEsq < ValorCorteEsq)&&(valorLinhaDir > ValorCorteDir))
  { 
    motorDir.run(FORWARD);
    motorEsq.run(RELEASE);
  }  

  //Se os sensor direito menor que valor de corte vira para esquerda 
  if((valorLinhaEsq > ValorCorteEsq)&&(valorLinhaDir < ValorCorteDir))
  { 
    motorDir.run(RELEASE);
    motorEsq.run(FORWARD);
  }
  
  if((valorLinhaEsq > ValorCorteEsq)&&(valorLinhaDir < ValorCorteDir))
  { 
    motorDir.run(RELEASE);
    motorEsq.run(FORWARD);
  }  

  delay(250);
}
