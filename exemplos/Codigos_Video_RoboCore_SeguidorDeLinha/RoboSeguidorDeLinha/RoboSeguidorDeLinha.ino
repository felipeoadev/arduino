/************************************\
|   Código Elaborado por RoboCore    |
| Sinta-se livre para usar ou editar |
|    SEMPRE cite a fonte do código   |
|          www.RoboCore.net          |
\************************************/

//quanto menor o valor, mais luz infravermelha chega ao sensor, portanto está no branco
//quanto maior o valor, menos luz infraverm. chega ao sensor, portanto está no preto

int sensorLinhaDir = A0;
int sensorLinhaEsq = A1;
int sensorCantoEsq = A2;
int sensorCantoDir = A3;

int ValorCorte = 700;

//Standard PWM DC control
int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;    //M1 Direction Control //motores da direita
int M2 = 7;    //M1 Direction Control //motores da esquerda

const int velocidade = 200;

int valorLinhaEsq, valorLinhaDir, valorCantoEsq, valorCantoDir = 0;  // variable to store the value coming from the sensor

void setup() {
    Serial.begin(9600);
    pinMode(4, OUTPUT); 
    pinMode(5, OUTPUT); 
    pinMode(6, OUTPUT); 
    pinMode(7, OUTPUT); 
    digitalWrite(M1,LOW);
    digitalWrite(M2,LOW); 
}

void loop() {
  
  valorLinhaEsq = analogRead(sensorLinhaEsq);    
  valorLinhaDir = analogRead(sensorLinhaDir);
  valorCantoEsq = analogRead(sensorCantoEsq);
  valorCantoDir = analogRead(sensorCantoDir);
  
  if((valorLinhaEsq > ValorCorte)&&(valorLinhaDir > ValorCorte))7
  {
    analogWrite (E1,velocidade);      
    analogWrite (E2,velocidade); 
    digitalWrite(M1,LOW);
    digitalWrite(M2,LOW);    
  }
  
if((valorLinhaEsq < ValorCorte)&&(valorLinhaDir > ValorCorte)){
    analogWrite (E1,velocidade);      
    analogWrite (E2,velocidade);
    digitalWrite(M1,HIGH);
    digitalWrite(M2,LOW);      
  }
  if((valorLinhaEsq > ValorCorte)&&(valorLinhaDir < ValorCorte))
  {
    analogWrite (E1,velocidade);      
    analogWrite (E2,velocidade); 
    digitalWrite(M1,LOW);
    digitalWrite(M2,HIGH);    
  }
  
  /*
  Serial.print("Linha Esq: ");
  Serial.print(valorLinhaEsq);
  Serial.print("   Linha Dir: ");
  Serial.print(valorLinhaDir);
  Serial.print("   Canto Esq: ");
  Serial.print(valorCantoEsq);
  Serial.print("   Canto Dir: ");
  Serial.println(valorCantoDir);
  
  delay(250);
  */
}
