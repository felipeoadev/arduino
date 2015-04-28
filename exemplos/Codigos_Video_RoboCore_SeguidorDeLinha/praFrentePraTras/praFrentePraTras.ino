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
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  analogWrite(E1, 100);
  analogWrite(E2, 100);
  
  delay(1000); //espera 1 segundo
  
  analogWrite(E1, 0);
  analogWrite(E2, 0);
  
  delay(1000); //espera 1 segundo
  
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 100);
  analogWrite(E2, 100);
  
  delay(1000); //espera 1 segundo
  
  analogWrite(E1, 0);
  analogWrite(E2, 0);
  
  delay(1000); //espera 1 segundo
  
  
}

