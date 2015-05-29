#include <Ultrasonic.h>
 
#define TRIGGER_PIN  12
#define ECHO_PIN     13

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

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
    
    //Define os pinos de 4 - 7 (Digital)
    for(int i = 4; i <= 7; i++)
    {
      pinMode(i, OUTPUT);
    }
  
    Serial.begin(9600); 
}

boolean obterDistancia()
{
  float cmMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  
  if (microsec > 430)
  {
    return true;
  }
  else
  {
    return false;
  }
  
  delay(1000);  
}

void loop() 
{     
  if (obterDistancia())
  {
    valorLinhaDir = analogRead(sensorLinhaDir);
    valorLinhaEsq = analogRead(sensorLinhaEsq);
  
    if ((valorLinhaEsq < ValorCorte) && (valorLinhaDir < ValorCorte))
    {
        Motor1(130,true);  //You can change the speed, such as Motor(50,true)
        Motor2(130,true); 
    }
  
    if((valorLinhaEsq > ValorCorte) && (valorLinhaDir < ValorCorte))
    {
        Motor1(130,true);
        Motor2(130,false);
    }
  
    if((valorLinhaDir > ValorCorte) && (valorLinhaEsq < ValorCorte))
    {     
        Motor1(130,false);
        Motor2(130,true);        
    } 
  }
  else
  {
    //Move para a Direita por 600 milissegundos
    Motor1(0,false);
    Motor2(0,false);
    delay(1000);
 
    //Move para Frente por 900 milissegundos
/*    Motor1(100,true);
    Motor2(100,true);
    delay(2000);
 
    //Move para a Direita por 400 milissegundos
    Motor1(100,true);
    Motor2(100,false);
    delay(1500);
 
    //Move para Frente por 1 segundo
    Motor1(100,true);
    Motor2(100,true);
    delay(1000);
 
    //Move para a Direita por 600 milissegundos
/*    dualmotor.M1move(255,1);
    dualmotor.M2move(255,0);
    delay(600);
 
    //Move para a Frente por 550 milissegundos
    dualmotor.M1move(255,1);
    dualmotor.M2move(255,1);
    delay(550);
 
    //Move para a Esquerda por 250 milissegundos
    dualmotor.M1move(255,0);
    dualmotor.M2move(255,1);
    delay(250);        */

  }
}

