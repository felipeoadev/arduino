/************************************\
|   Código Elaborado por RoboCore    |
| Sinta-se livre para usar ou editar |
|    SEMPRE cite a fonte do código   |
|          www.RoboCore.net          |
\************************************/

//quanto menor o valor, mais luz infravermelha chega ao sensor

int sensorLinha0 = A0;
int sensorLinha1 = A1;
int valorLinha0 = 0;  // variable to store the value coming from the sensor
int valorLinha1 = 0;  // variable to store the value coming from the sensor

void setup() 
{
    Serial.begin(9600);
}

void loop() {
  
  valorLinha0 = analogRead(sensorLinha0);
  valorLinha1 = analogRead(sensorLinha1);
  
  Serial.print("Linha 0 : ");
  Serial.println(valorLinha0); 
  
  Serial.print("Linha 1 : ");
  Serial.println(valorLinha1);   
  delay(250);
}
