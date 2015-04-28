/************************************\
|   Código Elaborado por RoboCore    |
| Sinta-se livre para usar ou editar |
|    SEMPRE cite a fonte do código   |
|          www.RoboCore.net          |
\************************************/

//quanto menor o valor, mais luz infravermelha chega ao sensor

int sensor = A0;

int valorSensor = 0;  

void setup() {
    Serial.begin(9600);
}

void loop() {
  
  valorSensor = analogRead(sensor);    

  Serial.print("Valor do Sensor: ");
  Serial.print(valorSensor);
  
  delay(250);
}
