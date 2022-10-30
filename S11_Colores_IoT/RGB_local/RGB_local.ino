#define LED_R 14
#define LED_G 27
#define LED_B 12
#define PIN_BUTTON 33

int led_status = 0;

// Debouncing (evitar rebote del botón)
unsigned long lastDebounceTime = 0; 
unsigned long debounceDelay = 200;

void IRAM_ATTR isr_button(){
  if((millis() - lastDebounceTime) > debounceDelay){
    led_status++;
    if(led_status >= 8) led_status = 0;
    // led_status = ()led_status >= 7) ? 0 : led_status++; Operador ternario
    lastDebounceTime = millis();
  }
}

void setup() {
  //Boton de interrupción
  pinMode(PIN_BUTTON, INPUT);
  attachInterrupt(PIN_BUTTON, isr_button, RISING);

  //Canales LED
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  // Menú de colores

 switch(led_status){
  case 1:  // RED
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, HIGH);
  break;

  case 2:  // GREEN
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, HIGH);
  break;

  case 3:  // BLUE
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, LOW);
  break;

  case 4:  // CYAN
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);
  break;

  case 5:  // YELLOW
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, HIGH);
  break;

  case 6:  // MAGENTA
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, LOW);
  break;

  case 7:  // WHITE
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);
  break;

  default:  // off
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, HIGH);
  break;
 }
 
}
