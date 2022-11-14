#define uS_to_S_Factor 1000000      // Factor de conversión s a us
#define SLEEP_TIME     5            // Tiempo que el ESP dormirá
#define LED_PIN        32           // LED
#define BUTTON_PIN     GPIO_NUM_33  // Botón

// Variable que se guarda en la memoria del RTC; se mantiene tras un deep sleep
RTC_DATA_ATTR int bootCount = 0;

void print_wakeup_reason(){
  esp_sleep_wakeup_cause_t wakeup_reason;

  wakeup_reason = esp_sleep_get_wakeup_cause();

  switch(wakeup_reason){
    case ESP_SLEEP_WAKEUP_EXT0:
      Serial.println("Inicio causado por señal en el RTC_IO (Periféricos del RTC)");
    break;

    case ESP_SLEEP_WAKEUP_EXT1:
      Serial.println("Inicio causado por señal en el RTC_CNTL");
    break;

    case ESP_SLEEP_WAKEUP_TIMER:
      Serial.println("Inicio causado por señal en un timer");
    break;

    case ESP_SLEEP_WAKEUP_TOUCHPAD:
      Serial.println("Inicio causado por señal en un pin Touch");
    break;

    case ESP_SLEEP_WAKEUP_ULP:
      Serial.println("Inicio causado por señal lanzada por el ULP Coprocessor");
    break;

    default:
      Serial.printf("El inicio no fue causado por ninguna razón conocida: %d\n", wakeup_reason);
  }
}

void setup() {
  Serial.begin(115200);
  delay(500);
  pinMode(LED_PIN, OUTPUT);

  bootCount++;
  Serial.println("Número de veces iniciado: " + String(bootCount));

  print_wakeup_reason();
  
  // Configuración Deep Sleep
  esp_sleep_enable_ext0_wakeup(BUTTON_PIN, HIGH);
  esp_sleep_enable_timer_wakeup(SLEEP_TIME*uS_to_S_Factor);
  Serial.println("Configurando ESP32 para dormir durante " + String(SLEEP_TIME) + " segundos.");

    Serial.println("ESP32 se va a dormir ahora.");
    esp_deep_sleep_start();
    
    Serial.println("Esta línea jamás se imprimirá");
}

void loop() {
  digitalWrite(LED_PIN, LOW);
  esp_light_sleep_start();

  digitalWrite(LED_PIN, HIGH);
  delay(500);
  
  print_wakeup_reason();

}
