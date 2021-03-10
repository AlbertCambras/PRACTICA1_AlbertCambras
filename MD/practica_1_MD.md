# PRACTICA 1 ALBERT CAMBRAS :  BLINK, ADC/DAC

Para hacer el código más interactivo y así también aprender, he hecho un menú de opciones para poder elegir entre el modo LED o el modo ADC/DAC.

Cuando subimos el código a la placa ESP32 tenemos que abrir el monitor donde aparecerá el menú de opciones.
(Si por alguna razón no apareciera este, pulsa el botón RESET).

Toda la informació recibida tanto por la placa como para el usuario, irá enviada por el puerto Serial, un puerto que efectúa la comunicación entre el ordenador y la placa, en este caso la ESP32.


Empezaré explicando la funcion 'elecció' donde está situado nuestro menú.

### FUNCIÓN ELECCIÓ
```cs
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

```
Para esta función he usado 'Serial.available()' que finalize solo cuando recibe los datos. Para entender esos datos recibidos, usamos Serial.read() que nos leerá los datos de entrada.
Si recibe un carácter 'a' nos iremos al modo LED y si ingresamos un carácter 'b' iremos al modo ADC/DAC.



![]time_diagram.json






