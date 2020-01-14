/*
 Realizar un programa que mediante teclado matricial (consultar) 
				 ingrese el tiempo en segundos de una cuenta regresiva. Esta cuenta,
				 decrece cada 1 segundo mediante timer
*/
#include <MsTimer2.h>
#include <LiquidCrystal.h>
#include <Keypad.h>     // libreria Keypad

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte fila = 4;     
const byte columna = 4;    
char keys[fila][columna] = {   
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[fila] = {34, 33, 32, 31}; 
byte colPins[columna] = {28, 27, 26, 25}; 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, fila, columna);  


int t=2000;
String dato ;
int val = 0;
int on = 0;

void setup() {
  MsTimer2::set(1000, conteo);
  MsTimer2::start();
  lcd.begin(16, 2);
  lcd.print("Valor a Ingresar");
  lcd.setCursor(0, 1);
}
void loop() {
  char key = keypad.getKey();
  if (key) {
    if (key == 'A' || key == 'B'|| key == '#' || key == '*') {
      on = 1 - on;
      lcd.setCursor(0, 0);
      lcd.print("              ");
      lcd.setCursor(9, 1);
      lcd.print("              ");
      lcd.setCursor(0, 0);
      lcd.print("CUENTA REGRESIVA");
    }
    else if (key == 'D'|| key == 'C' ) {
      lcd.setCursor(0, 0);
      lcd.print("               ");
      lcd.setCursor(0, 0);
      delay(t);
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("INGRESE NUMERO");
      lcd.setCursor(0, 1);
      key = ' ';
      dato=" ";
      on = 0;
      val = 0;
    }
    else {
      lcd.print(key);
      dato = dato + key;
    }
    val = dato.toInt();
  }
}
void conteo() {
  if (on == 1 ) {
    if (val > 0) {
      lcd.setCursor(9, 1);
      lcd.print("      ");
      lcd.setCursor(9, 1);
      lcd.print(val);
      val--;
    }
    else if (val == 0) {
      lcd.setCursor(9, 1);
      lcd.print("    ");
      lcd.setCursor(9, 1);
      lcd.print(val);
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("CONTEO FINAL");
    }
  }
}
