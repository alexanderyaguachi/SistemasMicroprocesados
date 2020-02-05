/*
  Realizar un programa que cada 5 segundos el sistema desactiva el conversor
  análogo digital, cada 8 segundos la comunicación serial y cada 12 segundos 
  un desactivación total. 
  Esta información debe verse en una LCD. Suba su enlace de su cuenta GitHub.
  */
  #include <LowPower.h>
  #include <avr/wdt.h>
  #include <EEPROM.h>
  #include<avr/sleep.h>
  #include <MsTimer2.h>
  #include <TimerOne.h>
  #include <avr/power.h>

  #include <LiquidCrystal.h>
  const int rs = 13, en =12 , d4 = 11, d5 = 10, d6 = 9, d7 = 8;
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  int conteo = 0;
  int dato;
  int on = 7;
  int t=10;
  int valor = EEPROM.read(0);

  void setup() {
    Timer1.initialize(1000000);
    Timer1.attachInterrupt(contador);
    power_all_enable();
    lcd.begin(16, 2);
    valor = 0;
  }

  void loop() {
    Serial.println(valor);
    dormir();
    lcd.setCursor(6, 1);
    lcd.print("Tiempo:" + String(conteo));
    dato = analogRead(0);
    lcd.setCursor(0, 1);
    lcd.print(dato);
  }
  void contador() {
  conteo++;
  }

  void dormir() {
    if (conteo == 5) {
    valor = valor + 1;
    lcd.setCursor(0, 0);
    lcd.print("CAD APAGADO");
    power_adc_disable();

    }
    if (conteo == 8) {
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print("CX APAGADO");
    power_spi_disable();
    }
    if (conteo == 12) {
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print("SISTEMAEN REPOSO");
    power_all_disable();
    }
    if (EEPROM.read(0) >= 12) {
    valor = 0;
    power_all_enable();
    EEPROM.write(0, valor);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SISTEMA");
    lcd.setCursor(0, 1);
    lcd.print("REINICIADO");
    digitalWrite(on, HIGH);
    delay(t);
    wdt_enable(WDTO_1S);
    }
  }
