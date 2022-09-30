#include "FS.h"
#include "SPIFFS.h"
#include <ArduinoJson.h>

// Función para deserializar y leer //
void readJsonTest(fs::FS &fs, const char * filename) {

  // Abrir el archivo para lectura //
  File file = fs.open(filename, "r");

  // Comprobar que se pudo abri el archivo //
  if(!file || file.isDirectory()){
        Serial.println("Error al abrir el documento");
        return;
    }

  // Asignar el archivo Json. La capacidad se determinó //
  // usando https://arduinojson.org/v6/assistant //
  StaticJsonDocument<96> doc;

  // Deserializar el archivo //
  DeserializationError error = deserializeJson(doc, file);

  // Comprobar si hubo error al desrializar //
   if (error) {
    Serial.print(F("deserialización fallida"));
    Serial.println(error.f_str());
    return;
   }

  // Imprimir lo que hay en el campo nombre_alumno del Json en el monitor serial //
  Serial.println(doc["nombre_alumno"].as<const char*>());
}

void setup() {

  // Inicializar comunicación serial //
  Serial.begin(9600);
  // Inicializar SPIFFS //
  if(!SPIFFS.begin(true)){
        Serial.println("SPIFFS Mount Failed");
        return;
    }

}

void loop() {

  // Ejecutar la función con el archivo con formato Json, cada 5s //
  readJsonTest(SPIFFS, "/json_test.txt");
  delay(5000);
  
}
