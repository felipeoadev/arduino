/************************************\
|   Código Elaborado por RoboCore    |
| Sinta-se livre para usar ou editar |
|    SEMPRE cite a fonte do código   |
|          www.RoboCore.net          |
\************************************/

//quanto menor o valor, mais luz infravermelha chega ao sensor

int sensorLinhaDir = A4;
int sensorLinhaEsq = A1;
int sensorCantoEsq = A2;
int sensorCantoDir = A3;

int ledPin = 13;      // select the pin for the LED
int valorLinhaEsq, valorLinhaDir, valorCantoEsq, valorCantoDir = 0;  // variable to store the value coming from the sensor

void setup() {
    Serial.begin(9600);
}

void loop() {
  
  valorLinhaEsq = analogRead(sensorLinhaEsq);    
  valorLinhaDir = analogRead(sensorLinhaDir);
  valorCantoEsq = analogRead(sensorCantoEsq);
  valorCantoDir = analogRead(sensorCantoDir);
  
  Serial.print("Linha Esq: ");
  Serial.print(valorLinhaEsq);
  Serial.print("   Linha Dir: ");
  Serial.print(valorLinhaDir);
  Serial.print("   Canto Esq: ");
  Serial.print(valorCantoEsq);
  Serial.print("   Canto Dir: ");
  Serial.println(valorCantoDir);
  
  delay(250);
}
