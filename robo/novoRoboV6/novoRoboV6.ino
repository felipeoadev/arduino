#include <Ultrasonic.h>
#include <Servo.h>
 
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
const int velocidade = 120;
int temObstaculo = 0;

int EN1 = 6;  
int EN2 = 5;  //Roboduino Motor shield uses Pin 9
int IN1 = 7;
int IN2 = 4; //Latest version use pin 4 instead of pin 8

/*Sensor fototransitor(Verifica se a bola esta na frente */
int objeto = 0;
int sensorBola = 11;
int comBola = 1;
int terminaLoop = 0;

/*Micro Servo*/
 Servo servoBola;
 int pos = 0;
  
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
    
    servoBola.attach(9);
    
    for(pos = 150; pos >= 1; pos-=1)     // goes from 180 degrees to 0 degrees
    {
      servoBola.write(pos);              // tell servo to go to position in variable 'pos'
    }      
    Serial.begin(9600); 
}

boolean obterDistancia()
{
  float cmMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.println(cmMsec);  
        
  if (cmMsec > 18.50 && cmMsec < 19.00)
  { 
    temObstaculo = 0;
  }
  else
  {
    temObstaculo = 1;
  }
  
//  delay(1000);  
}

void obterBola()
{
  objeto = digitalRead(sensorBola);  
  
  Serial.println(objeto);
    
  if (objeto == 0)  
  {  
    comBola = 0;
  }  
  else  
  {  
    comBola = 1;
  }
}

void desviaEsquerda()
{
      //Esquerda
      Motor1(velocidade, false);
      Motor2(velocidade, true);
      delay(900);
    
      //Frente
      Motor1(velocidade, true);
      Motor2(velocidade, true); 
      delay(1300);
      
      //Direita      
      Motor1(velocidade, true);
      Motor2(velocidade, false);      
      delay(1000);

      //Frente
      Motor1(velocidade,true);
      Motor2(velocidade,true); 
      delay(2000);
      
      //Direita      
      Motor1(velocidade,true);
      Motor2(velocidade,false);
      delay(1000);

      //Frente
      Motor1(velocidade,true);
      Motor2(velocidade,true); 
      delay(1400);      
       
      //Esquerda
      Motor1(velocidade,false);
      Motor2(velocidade,true);
      delay(900);
}

void loop() 
{     
  if (terminaLoop == 0)
  {        
    obterDistancia();
      
    if (temObstaculo == 0)
    {
      Motor1(0, false);
      Motor2(0, false);
      delay(1000);
      desviaEsquerda();  
    }
    else
    {
      obterBola();
      
      if (comBola == 0)
      {
          Motor1(0, false);
          Motor2(0, false);
        
          for(pos = 0; pos < 110; pos += 1)  // goes from 0 degrees to 180 degrees
          {                                  // in steps of 1 degree
              servoBola.write(pos);              // tell servo to go to position in variable 'pos'
          }
          
          Motor1(velocidade,true);
          Motor2(velocidade,false);
          delay(800);
          
          for(pos = 110; pos >= 1; pos-=1)     // goes from 180 degrees to 0 degrees
          {
            servoBola.write(pos);              // tell servo to go to position in variable 'pos'
          }      
          
          Motor1(0, false);
          Motor2(0, false);        
          
          comBola = 1; 
          terminaLoop = 1;
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
  }
  else
  {
    Motor1(0,false);
    Motor2(0,false);
    terminaLoop = 1;   
  }
}

