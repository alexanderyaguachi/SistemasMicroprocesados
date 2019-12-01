int leds[]={5,6,7,8,9,10,11,12};

int i=0;
int valor;
float a;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
  Serial.println("Ingrese el Valor");
  for (; i < 9; i++) {
    pinMode(leds[i], OUTPUT);   
  }
  i = 0;                      
}
void loop() {
  // put your main code here, to run repeatedly:
for (; i < 9; i++) {
    digitalWrite(leds[i], LOW);
  }
  while (Serial.available() == 0) {}
  a = Serial.parseFloat();
  Serial.println(a);

  if (int(a) == a) {
    if (a >= 0 && a <= 256) {
      valor = int(a);
      for (; i < 8; i++) {
        if (valor % 2 == 1) {
          digitalWrite(leds[i], HIGH);
        }
        else {
          digitalWrite(leds[i], LOW);
        }
        valor = valor / 2;
      }
    }
  }
  delay(3000);
}
