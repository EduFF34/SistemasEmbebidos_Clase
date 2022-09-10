// int pinLDR = 34;
// const int pinLDR = 34;
#define LDR_PIN 34

void setup() {
  
  Serial.begin(9600);

}

void loop() {
  
  int a = analogRead(LDR_PIN);
  Serial.println(a);
  delay(100);
  
}
