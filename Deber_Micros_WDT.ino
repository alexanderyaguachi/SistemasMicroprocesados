 /*
  *  Realizar un programa que mediante comunicación serial ingrese el tiempo
   de reset del arduino de la siguiente forma: A-> 1 s B-> 2s C-> 4s D-> 
   8s Hay que tener en cuenta que el sistema puede ser re
   configurado la veces necesarias(interrupciones)
 
  */
  #include <avr/wdt.h>
  #include <EEPROM.h>
  #include <TimerOne.h>
    String t;
    int cont = 0;
    int on = 0;
    int op = 0;
    void setup() {
      Serial.begin(9600);
      attachInterrupt(digitalPinToInterrupt(0), opcion, LOW);
      attachInterrupt(digitalPinToInterrupt(1), select, LOW);
      Serial.println("Opcion dos para Activar");
      Timer1.stop();
      cont = 0;
      op=0;
      t=" ";
      }
    void loop() {
      if (on == 1) {
      if (Serial.available() > 0 ) {
      t = Serial.readString();
      Timer1.initialize(1000000);
      Timer1.attachInterrupt(contador);
        }
        }
      }
    void opcion() {
      switch (on) {
        case 0:
          Serial.println("Tiempo");
          on++;
          break;
        case 1:
          Serial.println(" ");
          on = 0;
          break;

        }
      }
        void select() {
        op++;
        if (t=="A"&&op==1) {
        Serial.println("EN 1S SE REINICIA");
        wdt_enable(WDTO_1S);
        }
        if (t=="B"&&op==1) {{
        Serial.println("EN 2S SE REINICIA");
        wdt_enable(WDTO_2S);
        }
       if (t=="C"&&op==1) {
        Serial.println("EN 4S SE REINICIA");
        wdt_enable(WDTO_4S);
        }
        if (t=="D"&&op==1) {
        Serial.println("EN 8S SE REINICIA");
        wdt_enable(WDTO_8S);
        }
      }
    }
    void contador() {
      cont++;
      if(op==1){
      if(t=="A"){
       Serial.println(String(2-cont));
      }
      if (t=="B"){
       Serial.println(String(3-cont));
      }
      if (t=="C"){
       Serial.println(String(5-cont));
      }
      if (t=="D"){
       Serial.println(String(9-cont));
        }
       }
      }
