#define LM35_PIN 35

void setup() {
  
  Serial.begin(9600);

}

void loop() {

  // 5000 mV/(10 mV/°C * 4095) = 0.1221 -> resolución y conversión a °C
  int T = analogRead(LM35_PIN);
  Serial.println(T*0.1221);
  delay(200);
  
}
