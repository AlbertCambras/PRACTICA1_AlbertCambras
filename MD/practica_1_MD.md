# PRACTICA 1 ALBERT CAMBRAS :  BLINK, ADC/DAC

Para hacer el código más interactivo y así también aprender, he hecho un menú de opciones para poder elegir entre el modo LED o el modo ADC/DAC.

Cuando subimos el código a la placa ESP32 tenemos que abrir el monitor donde aparecerá el menú de opciones.
(Si por alguna razón no apareciera este, pulsa el botón RESET).
Para acceder al modo LED tenemos que pulsar la tecla a y para el otro modo, la tecla b.

Toda la informació recibida tanto por la placa como para el usuario, irá enviada por el puerto Serial, un puerto que efectúa la comunicación entre el ordenador y la placa, en este caso la ESP32.


Empezaré explicando la funcion 'elecció' donde está situado nuestro menú.

`var t=1;`
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


## TRABAJOS Y PREGUNTAS 

1. Generar el programa  y subir el codigo  al github de cada uno 
2. generar un informe fichero  informe.MD ( markdown  ) donde se muestr el codigo  , un diagrama de flujo y un diagrama de tiempos 
3. Responder a la siguiente pregunta en el programa que se ha realizado cual es el tiempo libre que tiene el procesador ?


# EJERCICIOS voluntarios  DE MEJORA DE NOTA

Elejir entre cualquiera de los siguentes 

* leer el valor de un convertidor  A/D  de entrada ; sacarlo por el puerto serie  y sacar el mismo valor  por otro pin  D/A

https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/

* Leer el valor del sensor de temperatura interno y sacarlo por el puerto serie 

el resultado se ha de subir al github de cada uno y realizar un informe .MD 

https://gist.github.com/xxlukas42/7e7e18604f61529b8398f7fcc5785251




