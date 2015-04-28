/************************************\
|   Código Elaborado por RoboCore    |
| Sinta-se livre para usar ou editar |
|    SEMPRE cite a fonte do código   |
|          www.RoboCore.net          |
\************************************/

//quanto menor o valor, mais luz infravermelha chega ao sensor, portanto está no branco
//quanto maior o valor, menos luz infraverm. chega ao sensor, portanto está no preto

int sensorLinhaDir = A3;
int sensorLinhaEsq = A2;
int sensorCantoEsq = A1;
int sensorCantoDir = A4;

int ValorCorte = 700;

//Standard PWM DC control
int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;    //M1 Direction Control //motores da direita
int M2 = 7;    //M1 Direction Control //motores da esquerda

const int velocidade = 200;

int valorLinhaEsq, valorLinhaDir, valorCantoEsq, valorCantoDir = 0;  // variable to store the value coming from the sensor


void setup() {
    
    pinMode(4, OUTPUT); 
    pinMode(5, OUTPUT); 
    pinMode(6, OUTPUT); 
    pinMode(7, OUTPUT); 
       
}

void loop() {
  
  valorLinhaEsq = analogRead(sensorLinhaEsq);    
  valorLinhaDir = analogRead(sensorLinhaDir);
  valorCantoEsq = analogRead(sensorCantoEsq);
  valorCantoDir = analogRead(sensorCantoDir);
  
  if((valorLinhaEsq > ValorCorte)&&(valorLinhaDir > ValorCorte)){
    analogWrite (E1,velocidade);  //VELOCIDADE    
    analogWrite (E2,velocidade);  //VELOCIDADE
    digitalWrite(M1,LOW);  //SENTIDO DE ROTACAO
    digitalWrite(M2,LOW);  //SENTIDO DE ROTACAO  
  }
  
if((valorLinhaEsq < ValorCorte)&&(valorLinhaDir > ValorCorte)){
    analogWrite (E1,velocidade);  //CURVA PARA DIREITA    
    analogWrite (E2,velocidade);
    digitalWrite(M1,HIGH);
    digitalWrite(M2,LOW);      
  }
  if((valorLinhaEsq > ValorCorte)&&(valorLinhaDir < ValorCorte)){
    analogWrite (E1,velocidade);   // CURVA PARA ESQUERDA   
    analogWrite (E2,velocidade); 
    digitalWrite(M1,LOW);
    digitalWrite(M2,HIGH);    
  }
  
  if((valorLinhaEsq > ValorCorte)&&(valorLinhaDir > ValorCorte)
                      &&(valorCantoEsq > ValorCorte)&&(valorCantoDir > ValorCorte)){
    digitalWrite(M1,LOW); //SENTIDO DE ROTACAO
    digitalWrite(M2,HIGH); //SENTIDO DE ROTACAO
    analogWrite (E1,velocidade);  //VELOCIDADE     
    analogWrite (E2,velocidade);  //VELOCIDADE   
    delay(500);
 }
  
  
}
