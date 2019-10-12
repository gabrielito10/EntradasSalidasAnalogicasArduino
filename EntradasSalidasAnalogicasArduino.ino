/*
Programa para conectar un potenciometro conectado al puerto analogico A0 y sacar 
por los pines PWM o analogicos 3,5,6,9 conectados a leds
los cuales se encenderan de acuerdo a la intensidad del potenciometro

Material:
-Arduino uno
-4 Resistencias de 330 ohmios
-4 leds
- Protoboard
- Potenciometro 5k

Autor: Juan Gabriel Ibañez Cedillo
*/
void setup()
{
    //Pines 3,5,6,9 como salida
    pinMode(3,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(9,OUTPUT);
}
void loop()
{
    //Recibimos el valor del potenciometro el cual devolvera un valor entre 0 y 1023
    int valorLeido=analogRead(A0);
    
    //convertimos el valor obtenido entre 0 y 1023 a un rango entre 0 y 255
    //esto porque las entradas analogicas trabajan a 10 bits 
    //y las salidas solo trabajan a 8 bits 
    int valorConvertido=map(valorLeido,0,1023,0,255);
    
    //asignamos el valor convertido a las salidas analogicas
    analogWrite(3,valorConvertido);
    analogWrite(5,valorConvertido);
    analogWrite(6,valorConvertido);
    analogWrite(9,valorConvertido);
    delay(50);
}