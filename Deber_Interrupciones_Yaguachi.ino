/*
  Realizar un ejercicio en el cual tenga las etapas de: 
  (i)Ingreso de datos y (ii) ordenamiento 
  (i)Al ingresar la palabra solo pueden ser números 
  por comunicación serial. (ii) Una vez ingresados lo 
  números, ordenarlos de menor a mayor e imprimirlo 
  por comunicación serial.
 */
 /*
  * Yaguachi ALexander
  */

String dato;
String val;
int i = 0;
int b;
int d;
int on = 0;
int t=500;
void setup() {
 
  Serial.begin(9600);
  Serial.println("SISTEMA ENCENDIDO");
  delay(t);
  Serial.println(" Realizar un ejercicio en el cual tenga las etapas:");
  delay(t);
  Serial.println("Ingrese los numeros del 0 a 9 ");
  delay(t);
  attachInterrupt(0, interrupcion1, LOW);
}
void loop() {
  if (Serial.available() > 0) {
    dato = Serial.readString();
    Serial.println("");
    delay(t);
    Serial.println("Ordenar numero ");
    delay(t);
     Serial.println("Presione la Interrupcion ");
     delay(t);
  }
  if (on == 1) {
    int num[dato.length()];                 
    for (i = 0; i < dato.length(); i++) {   
      val = dato.substring(i, (i + 1));    
      num[i] = val.toInt();                
    }
    do {                                   
      b = 0;
      for (i = 0; i < dato.length(); i++) { 
        if (num[i] > num[i + 1]) {          
          b = 1;
          d = num[i];
          num[i] = num[i + 1];
          num[i + 1] = d;
        }
      }
    }
    while (b);
    for (i = 0; i < dato.length(); i++) { 
      Serial.print(num[i]);
    }
    on = 0;
  }
}
void interrupcion1() {
  on = 1 - on;

}
