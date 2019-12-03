//UNIVERSIDAD TECNICA DEL NORTE
//Alexander Yaguachi
//Repaso 3 Juego de Luces
//Realizar un programa que active 4 juegos de luces con 5 leds al ingresar datos por comunicación serial de 
//la siguiente forma: ACBF-> Activa juego 1 ACGF -> Activa juego 2 ADBF -> Activa juego 3 ADBH -> Activa juego 4


int t=200;                       
int leds[5]={9,10,11,12,13};       //Declaramos un vector de 5 posiciones
int rdm;
int i=0;
int j=0;
String letra;
void setup() {
      
     for(int i=0;i<5;i++){
        pinMode(leds[i],OUTPUT);
      }
      Serial.begin(9600);
      Serial.println("Juego de Luces");
      
}
void loop() {

  if (Serial.available() > 0) {
    letra = Serial.readString();
    Serial.println("");
    if (letra == "ACBF") {
      juego1();

    }
    else if (letra == "ACGF") {
      juego2();
    }
    else if (letra == "ADBF") {
      juego3();
    }
    else if (letra == "ADBH") {
      juego4();
    }
  }
  juego1(); 
  delay(250); //Hace una pausa entre el juego 1 y 2
  juego2(); 
  delay(250); //Hace una pausa entre el juego 2 y 3
  juego3(); 
  delay(250); //Hace una pausa entre el juego 3 y 4
  juego4(); 
 

}
void juego1(){
  
  for(int i=0;i<5;i=i+2){       //Indica la secuencia de pines en alto "1,3,5"
    digitalWrite(leds[i],HIGH);
    delay(t);                     //Reliza una pausa durante un tiempo
    digitalWrite(leds[i],LOW);
    delay(t);                     //Reliza una pausa durante un tiempo
    }
  }
void juego2(){
   for(int i=1;i<5;i=i+2){      //Indica la secuencia de pines en alto "2,4"
    digitalWrite(leds[i],HIGH);
    delay(t);                   //Reliza una pausa durante un tiempo
    digitalWrite(leds[i],LOW);
    delay(t);
    }
  }
void juego3(){
   rdm=random(5);              //Imprime un led aleatorio dentro del vector de 5 posiciones
    digitalWrite(leds[rdm],HIGH);
    delay(t);
    digitalWrite(leds[rdm],LOW);
    delay(t);
  }
void juego4(){
  for(i=0;i<5;i++){//los leds se encenderan de forma ascendente.
  digitalWrite(leds[i],HIGH);
  delay(t);  
  }
  for(i=5;i>=0;i--){//los leds de apagaran en forma descendente.
  digitalWrite(leds[i],LOW); 
  delay(t);  
  }
 }
 

  
