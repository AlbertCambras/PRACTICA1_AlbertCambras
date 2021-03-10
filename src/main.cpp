#include <Arduino.h>
#include <ArduinoJson.h>
int pin_DAC=34;
int pin_ADC=25;
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
        Serial.println("VALOR:");
        Serial.println(valor);
        delay(100);
        // Si conectem el pin 25 amb el 32, tindrem que el voltatge del 32 anira variant segons el que treu el pin 25 en analògic.
        delay(10);
      }
  
}


void coments(){
    Serial.println("1. LED");
    Serial.println("2. ADC");
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

}

void loop() {
  delay(100);
  eleccio();
}