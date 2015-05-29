
int sensorLinhaDir = A0;    // select the pin for the LED
int valorLinhaDir  = 0;  // variable to store the value coming from the sensor
int sensorLinhaEsq = A1;    // select the pin for the LED
int valorLinhaEsq  = 0;  // variable to store the value coming from the sensor

//Valor de corte < 700 branco > preto
int ValorCorte = 700;

//Velocidade do carrinho
const int velocidade = 160;

int EN1 = 6;  
int EN2 = 5;  //Roboduino Motor shield uses Pin 9
int IN1 = 7;
int IN2 = 4; //Latest version use pin 4 instead of pin 8
  
 
//Funcoes do Motor 1 
void Motor1(int pwm, boolean reverse)
{
   analogWrite(EN1,pwm); //set pwm control, 0 for stop, and 255 for maximum speed
  
   if(reverse)
   {   
      digitalWrite(IN1,HIGH);    
   }
  else
  {
      digitalWrite(IN1,LOW);    
  }
}  
         
void Motor2(int pwm, boolean reverse)
{
  analogWrite(EN2,pwm);
  if(reverse)
  { 
     digitalWrite(IN2,HIGH);    
  }
  else
  {
    digitalWrite(IN2,LOW);    
  }
}  



void setup() 
{
      int i;
   // for(i=6;i<=9;i++) //For Roboduino Motor Shield
   // pinMode(i, OUTPUT);  //set pin 6,7,8,9 to output mode
 
    for(i=4;i<=7;i++)  //For Arduino Motor Shield
    pinMode(i, OUTPUT);  //set pin 4,5,6,7 to output mode
  
    Serial.begin(9600); 
}

void loop() 
{   
  valorLinhaDir = analogRead(sensorLinhaDir);
  valorLinhaEsq = analogRead(sensorLinhaEsq);
  
  if ((valorLinhaEsq < ValorCorte) && (valorLinhaDir < ValorCorte))
  {
      Motor1(100,true);  //You can change the speed, such as Motor(50,true)
      Motor2(100,true); 
  }
  
  if((valorLinhaEsq > ValorCorte) && (valorLinhaDir < ValorCorte))
  {
      Motor1(100,false);
      Motor2(100,true);  
  }
  
  if((valorLinhaDir > ValorCorte) && (valorLinhaEsq < ValorCorte))
  {
      Motor1(100,true);
      Motor2(100,false);
  }   
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
