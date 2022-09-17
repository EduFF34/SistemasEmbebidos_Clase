// Lecturas desde el sensor barométrico
#include <Adafruit_BMP280.h>
#include <SD.h>
#include <sd_defines.h>
#include <sd_diskio.h>

#define PIN_LED 32

Adafruit_BMP280 bmp;
File readings;
File read_me;

char payload[50]; // Datos a escribir en SD y Serial

void setup() {

  Serial.begin(115200); // Inicializar serial UART-USB
  bmp.begin(0x76); // Inicializar comunicación I2C con el sensor barométrico
  SD.begin(); // Inicializar SD

  pinMode(PIN_LED, OUTPUT);

  // README
  read_me = SD.open("/README.txt", FILE_WRITE);
  read_me.print("Archivo de lecturas del sensor BMP280.\n"\
                "Temperatura [°C], Presión [Pa]");
  read_me.close();

}

void loop() {

  // Escribir lecturas en el payload
  sprintf(payload, "%.2f,%.2f", bmp.readTemperature(), bmp.readPressure());
  Serial.println(payload); // Imprimir el payload

  digitalWrite(PIN_LED, HIGH); // Encender Led al escribir
    readings = SD.open("/readings.csv", FILE_APPEND); // Abro archivo
    readings.println(payload); // Escribir en el archivo
    readings.close(); // Cerramos archivo
  digitalWrite(PIN_LED, LOW); // Apgamos Led tras escribir
  
  delay(900);
  

}
