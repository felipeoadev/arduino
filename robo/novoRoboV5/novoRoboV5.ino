#include <Ultrasonic.h>
 
#define TRIGGER_PIN  12
#define ECHO_PIN     13

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

int sensorLinhaDir = 0;    // select the pin for the LED
int valorLinhaDir  = 0;  // variable to store the value coming from the sensor
int sensorLinhaEsq = 1;    // select the pin for the LED
int valorLinhaEsq  = 0;  // variable to store the value coming from the sensor

//Valor de corte < 700 branco > preto
int ValorCorte = 700;

//Velocidade do carrinho
const int velocidade = 130;

int EN1 = 6;  
int EN2 = 5;  //Roboduino Motor shield uses Pin 9
int IN1 = 7;
int IN2 = 4; //Latest version use pin 4 instead of pin 8

/*Sensor fototransitor(Verifica se a bola esta na fente */
int objeto = 0;
int sensorBola = 11;
  
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

boolean obterBola()
{
  objeto = digitalRead(sensorBola);  
  
  if (objeto == 0)  
  {  
    return true;
  }  
  else  
  {  
    return false;
  }
}

boolean obterDistancia()
{
  float cmMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  Serial.println(microsec);
    
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
  if (!obterDistancia())
  {
      Motor1(velocidade,true);
      Motor2(velocidade,false);
      delay(1000);
    
      Motor1(velocidade,true);
      Motor2(velocidade,true); 
      delay(2000);
      
      Motor1(velocidade,false);
      Motor2(velocidade,true);
      delay(1000);

      Motor1(velocidade,true);
      Motor2(velocidade,true); 
      delay(2000);      
  }
  if (obterBola())
  {
        Motor1(130,true);
        Motor2(130,false);
        delay(800);
  }
  else
  {
    valorLinhaDir = analogRead(sensorLinhaDir);
    valorLinhaEsq = analogRead(sensorLinhaEsq);
 
    if ((valorLinhaEsq < ValorCorte) && (valorLinhaDir < ValorCorte))
    {
        Motor1(velocidade,true);  //You can change the speed, such as Motor(50,true)
        Motor2(velocidade,true); 
    }
    
    if((valorLinhaEsq > ValorCorte) && (valorLinhaDir < ValorCorte))
    {
        Motor1(velocidade,true);
        Motor2(velocidade,false);
    }
  
    if((valorLinhaDir > ValorCorte) && (valorLinhaEsq < ValorCorte))
    {     
        Motor1(velocidade,false);
        Motor2(velocidade,true);        
    }
   
    if((valorLinhaDir > ValorCorte) && (valorLinhaEsq > ValorCorte))
    {     
      if (valorLinhaDir > valorLinhaEsq)  
      {
        Motor1(velocidade,false);
        Motor2(velocidade,true);
        delay(500);
      }
      else
      {
        Motor1(velocidade,true);
        Motor2(velocidade,false);
        delay(500);
      }
  
    }
   
  }
}

