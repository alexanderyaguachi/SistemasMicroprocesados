
#include <LiquidCrystal.h> //
int t =300;
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// Textos
String dato ;
 
void setup() {
  // Configuración monitor serie
  
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.blink();
}
 
void loop() {
 if (Serial.available() > 0) {
    dato = Serial.readString();
  int tam_dato=dato.length();
  //Desplazamiento Izquierda
  for(int i=tam_dato; i>0 ; i--)
  {
    String val = dato.substring(i-1);
    // Limpiamos pantalla
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(val);
    delay(t);
  }
  
  // Desplacamiento Derecho
  for(int i=1; i<=16;i++)
  {
    lcd.clear();
    lcd.setCursor(i, 0);
    lcd.print(dato);
    delay(t);
  }
 
  for(int i=16;i>=1;i--)
  {
    lcd.clear();
    lcd.setCursor(i, 1);
    lcd.print(dato);
    delay(t);
  }
  for(int i=1; i<=tam_dato ; i++)
  {
    String val = dato.substring(i-1);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(val);
    delay(t);
  }
 }
}
