struct Button {
  const int PIN;
  int numTimesButtonPressed;
  bool pressed;
  bool bStatus;
};

Button button1 = {33, 0, false, false};

void IRAM_ATTR isr_button() {

  button1.numTimesButtonPressed += 1;
  button1.pressed = true;
  button1.bStatus ^= 1;
  
}

void setup() {
  
  Serial.begin(115200);
  pinMode(button1.PIN, INPUT);
  attachInterrupt(button1.PIN, isr_button, RISING);
  
}

void loop() {
  
  if(button1.bStatus){
    Serial.printf("El botón se ha presionado %u veces \n", button1.numTimesButtonPressed);
    button1.pressed = false;
  }else{
    Serial.println("bStatus: ");
    Serial.println(button1.bStatus);
  }

  delay(800);

}
