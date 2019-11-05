/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * Realizar un contador binario de 6 bits, cuyo incremento se lo realiza con un pulsador.
 * 
 */
int boton=2;
int c_binario[6]={13,12,11,10,9,8};
int i=0;
int j=0;
void setup() {
  // put your setup code here, to run once:
  int i=0;
  for(i=0;i<6;i++){
    pinMode(c_binario[i],OUTPUT);
    pinMode(boton,INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
    if(digitalRead(boton)==HIGH){
    for(i=0;i<32;i++){
      for(j=0;j<6;j++){
        if(((i>>j)&1)==1)
          digitalWrite(c_binario[j],HIGH);
          else
          digitalWrite(c_binario[j],LOW);
      }
      delay(600);
    }
}else{
    digitalWrite(  1, LOW ) ;
    digitalWrite(  2, LOW ) ;
    digitalWrite(  3, LOW ) ;
    digitalWrite(  4, LOW ) ;
    digitalWrite(  5, LOW ) ;
    digitalWrite(  6, LOW ) ;
    delay (600);
}
}
