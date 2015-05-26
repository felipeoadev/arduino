/************************************\
|   Código Elaborado por RoboCore    |
| Sinta-se livre para usar ou editar |
|    SEMPRE cite a fonte do código   |
|          www.RoboCore.net          |
\************************************/

//quanto menor o valor, mais luz infravermelha chega ao sensor

#include <AFMotor.h>
#include <Servo.h> 

//Define os motores do shield que serão usados
AF_DCMotor motorDir(2), motorEsq(1);

int sensorLinhaDir = 8;    // select the pin for the LED
int valorLinhaDir  = 0;  // variable to store the value coming from the sensor
int sensorLinhaEsq = 9;    // select the pin for the LED
int valorLinhaEsq  = 0;  // variable to store the value coming from the sensor
int sensorLinhaMei = 10;    // select the pin for the LED
int valorLinhaMei  = 0;  // variable to store the value coming from the sensor

//Valor de corte < 700 branco > preto
int ValorCorte = 500;

//Velocidade do carrinho
const int velocidade = 160;

void setup() 
{
    Serial.begin(9600); 
    motorDir.setSpeed(velocidade);
    motorEsq.setSpeed(velocidade);
}

/* Tudo no bRanco < 30
 *  Meio no preto e os dois no branco 
   Meio > 750
   Lados < 35
   
   

*/

void loop() 
{   
  valorLinhaDir = analogRead(sensorLinhaDir);
  valorLinhaMei = analogRead(sensorLinhaMei);
  valorLinhaEsq = analogRead(sensorLinhaEsq);

  Serial.print("Esquerda ");    
  Serial.println(valorLinhaEsq);
  Serial.print("Meio ");    
  Serial.println(valorLinhaMei);
  Serial.print("Direita ");    
  Serial.println(valorLinhaDir);
  Serial.println("");


     motorDir.run(FORWARD);
       motorEsq .run(FORWARD);
}   
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  /*if((valorLinhaMei > ValorCorte) && (valorLinhaEsq < ValorCorte) && (valorLinhaDir < ValorCorte))
  {
     motorDir.run(FORWARD);
     motorEsq.run(FORWARD);
     Serial.println("Reto");
     Serial.println("");     
     
    motorDir.setSpeed(velocidade);
    motorEsq.setSpeed(velocidade);
     
  }
  
  if((valorLinhaEsq > ValorCorte) && (valorLinhaDir < ValorCorte) && (valorLinhaMei < ValorCorte))
  {
     Serial.println("Esquerda");
     Serial.println("");     
     motorDir.run(FORWARD);
     motorEsq.run(RELEASE);      
         motorDir.setSpeed(velocidade);
    motorEsq.setSpeed(velocidade);

  }
  
  if((valorLinhaDir > ValorCorte) && (valorLinhaEsq < ValorCorte) && (valorLinhaMei < ValorCorte))
  {
     Serial.println("Direita");
     Serial.println("");     
     motorDir.run(RELEASE);
     motorEsq.run(FORWARD);      
     motorDir.setSpeed(velocidade);
     motorEsq.setSpeed(velocidade);

  }  
  
  if((valorLinhaMei < ValorCorte) && (valorLinhaDir < ValorCorte) && (valorLinhaDir < ValorCorte))
  {
      motorDir.run(FORWARD);
      motorEsq.run(FORWARD);
      Serial.println("Reto 2");
      Serial.println("");     
      motorDir.setSpeed(velocidade);
      motorEsq.setSpeed(velocidade);
  }
  
  if((valorLinhaEsq > ValorCorte) && (valorLinhaMei > ValorCorte) && (valorLinhaDir < ValorCorte) )
  {
      Serial.println("Esquerda 2");
      Serial.println("");     
      motorDir.run(FORWARD);
      motorEsq.run(RELEASE);      
      motorDir.setSpeed(velocidade);
      motorEsq.setSpeed(velocidade);
  } 
   
  if((valorLinhaDir > ValorCorte) && (valorLinhaMei > ValorCorte) && (valorLinhaEsq < ValorCorte) )
  {
     Serial.println("Direita 2");
     Serial.println("");     
     motorDir.run(RELEASE);
     motorEsq.run(FORWARD);      
     motorDir.setSpeed(velocidade);
     motorEsq.setSpeed(velocidade);

  } 
  
  delay(500);
}*/
