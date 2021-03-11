#include <Arduino.h>
#include <ArduinoJson.h>
int pin_DAC=25;
int pin_ADC=34;
int LED=2;


//DECLARO VARIABLES GLOBALS
//Declaro els pins amb un nom per a que s'entengui bé el codi;


void led(){
  for(int i=0;i<10;i++){
    digitalWrite(LED,HIGH);
    Serial.println("ON");
    delay(500);
    digitalWrite(LED,LOW);
    Serial.println("OFF");
    delay(500);
  }
}

void adc_dac(){

  int valor=0;
 
      for (int cont= 0; cont < 256; cont++){
        dacWrite(pin_DAC, cont);
        delay(50);
        valor = analogRead(pin_ADC);
        valor = map(valor, 0, 4096, 0, 255); // EL MAXIM QUE OBTINDRE AL LLEGIR SERA 4096 (2^12), AIXÍ QUE ARA EL 4096 SERÀ 255;
        Serial.println("VALOR:");
        Serial.println(valor);
        delay(100);
      }
  
}


void coments(){
    Serial.println("a. LED");
    Serial.println("b. ADC");
}

void eleccio(){
  char a;
  int b=0;
  if (Serial.available()){
    if(b==0){
      coments();
      a=Serial.read();
      }
    //coments();
    if(a=='a'){
      b=1;
      led();
      coments();
      a=Serial.read();
    }
    else if(a=='b'){
      b=1;
      adc_dac();
      coments();
      a=Serial.read();

    }
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  analogReadResolution(12); // NO CAL JA QUE VE PER DEFECTE
}

void loop() {
  delay(100);
  eleccio();
}