/*
 *   Realizar un programa que por comunicación serial se ingrese 
     el límite de lectura del conversor análogo digital (0-1024) 
     si el valor del conversor supera dicho valor, se enciende
     un led. Suba su enlace del GitHub.

 */
float valor;
int led_encendido=10;
void setup() {
  // put your setup code here, to run once:

    Serial.begin(9600);
    pinMode(led_encendido,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    valor = (analogRead(0) * 1024.0) / 1023.0;
   if (valor > 1024.0) {
        digitalWrite(led_encendido, HIGH);
      }
      else{
        digitalWrite(led_encendido, LOW);
        }
 Serial.print(String(analogRead(0))+ ": ");
 delay(100);
}
