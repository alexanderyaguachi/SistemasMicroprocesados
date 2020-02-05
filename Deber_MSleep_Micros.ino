
  #include <TimerOne.h>
  #include <avr/wdt.h>
  #include<avr/sleep.h>
  #include<avr/power.h>
  #include<EEPROM.h>
  int conteo = 0;
  int valor;

  void setup() {
    Serial.begin(9600);
    valor = EEPROM.read(0);
    EEPROM.write(0, 1);
    attachInterrupt(digitalPinToInterrupt(0), levantar, LOW);
    Timer1.initialize(1000000);
    Timer1.attachInterrupt(contador);
    Serial.begin(9600);
    Serial.println(valor);
    }
  void loop() {
     if (conteo == 2 ) {
    Serial.println("Sistema Activo");
    Serial.println(conteo);
    }
     if (conteo == 4) {
    Serial.println("Sistema en Reposo");
    EEPROM.update(0, 0);
    sleep_mode();
    sleep_enable();
    }  
    if (conteo == 10) {
    sleep_disable();
    conteo = 0;
     }
   }
  void contador() {
    conteo++;
  }
  void levantar() {
    sleep_disable();
    Serial.println("Sistema Encendido");
    conteo = 0;
  }

