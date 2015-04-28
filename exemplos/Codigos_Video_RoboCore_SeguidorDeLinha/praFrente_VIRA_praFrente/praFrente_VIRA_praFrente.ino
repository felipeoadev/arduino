/************************************\
|   Código Elaborado por RoboCore    |
| Sinta-se livre para usar ou editar |
|    SEMPRE cite a fonte do código   |
|          www.RoboCore.net          |
\************************************/

//Standard PWM DC control
int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;    //M1 Direction Control
int M2 = 7;    //M1 Direction Control
 
void setup(void){ 
  int i;
  for(i=4;i<=7;i++)
    pinMode(i, OUTPUT); 
} 

void loop(){
  digitalWrite(M1, LOW); //rotacao no sentido horario do canal 1
  digitalWrite(M2, LOW); //rotacao no sentido horario do canal 2
  analogWrite(E1, 100); //informa a velocidade do canal 1 - 0 É A VELOCIDADE MINIMA
  analogWrite(E2, 100); //informa a velocidade do canal 2 - 255 É A VELOCIDADE MÁXIMA
  
  delay(1000); //espera 1 segundo
  
  analogWrite(E1, 0);
  analogWrite(E2, 0);
  
  delay(1000);
  
  digitalWrite(M1, LOW); //rotacao no sentido horario do canal 1
  digitalWrite(M2, HIGH); //rotacao no sentido horario do canal 2
  analogWrite(E1, 255);
  analogWrite(E2, 255);
  
  delay(500); //espera 1 segundo
  
  analogWrite(E1, 0);
  analogWrite(E2, 0);
  
  delay(1000);
  
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  analogWrite(E1, 100);
  analogWrite(E2, 100);
  
  delay(1000); //espera 1 segundo
  
  analogWrite(E1, 0);
  analogWrite(E2, 0);
  
  delay(1000);
  
  digitalWrite(M1, LOW); //rotacao no sentido horario do canal 1
  digitalWrite(M2, HIGH); //rotacao no sentido horario do canal 2
  analogWrite(E1, 255);
  analogWrite(E2, 255);
  
  delay(500); //espera 1 segundo
  
  analogWrite(E1, 0);
  analogWrite(E2, 0);
  
  delay(1000);
   
}

