#define PIN_Button 33
#define PIN_Rel 15

bool rel_status = 0;

// Debouncing
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 250;

// Interrupcion_boton. Al presionarlo cambia el color del led
void IRAM_ATTR isr_button(){

  if ((millis() - lastDebounceTime) > debounceDelay){
     rel_status = !rel_status; 
     lastDebounceTime = millis();
  }
  
}

void setup() {

  Serial.begin(115200);

  // Boton de interrupcion
  pinMode(PIN_Button, INPUT);
  attachInterrupt(PIN_Button, isr_button, RISING);

  // Relevador
  pinMode(PIN_Rel, OUTPUT);

}

void loop() {

  // Estado del relevador

  if(rel_status){digitalWrite(PIN_Rel, HIGH);}
  else{digitalWrite(PIN_Rel, LOW);}
  }
  
