int objeto = 0;  
   
void setup()  
{  
  pinMode(22, INPUT); //Pino ligado ao coletor do fototransistor  
  Serial.begin(9600);  
}  
   
void loop()  
{  
  objeto = digitalRead(22);  
  if (objeto == 0)  
  {  
    Serial.println("Objeto : Detectado");  
  }  
  else  
  {  
    Serial.println("Objeto : Ausente !");  
  }  
} 
