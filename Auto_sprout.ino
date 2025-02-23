#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define BLYNK_TEMPLATE_ID "TMPL3M4brZu4G"
#define BLYNK_TEMPLATE_NAME "plant"
#define BLYNK_AUTH_TOKEN "9_ygkzsx_7bofdolk44ZKLdPw6p2Ceax"

#define SOIL_MOISTURE_PIN A0
#define TEMPERATURE_PIN D2
#define PUMP_PIN D1
#define DHTTYPE DHT11

DHT dht(TEMPERATURE_PIN, DHTTYPE);
BlynkTimer timer; // Avoids blocking delays

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Galaxy";
char pass[] = "krish123";

int moistureValue;
float temperature, humidity;
int moistureThreshold = 500; // Initial threshold

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, LOW); // Ensure pump is off initially

  timer.setInterval(1000L, readSensors); // Read sensors every 1 second
}

void loop() {
  Blynk.run();
  timer.run(); // Non-blocking function
  controlPump();
}

void readSensors() {
  moistureValue = analogRead(SOIL_MOISTURE_PIN);
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  Serial.print("Moisture: "); Serial.println(moistureValue);
  Serial.print("Temperature: "); Serial.println(temperature);
  Serial.print("Humidity: "); Serial.println(humidity);

  Blynk.virtualWrite(V0, moistureValue); // Soil moisture gauge
  Blynk.virtualWrite(V1, temperature);  // Temperature gauge
  Blynk.virtualWrite(V2, humidity);     // Humidity gauge
  Blynk.virtualWrite(V3, moistureThreshold); // Display moisture threshold
}

void controlPump() {
  if (moistureValue > moistureThreshold) {
    Serial.println("Watering...");
    digitalWrite(PUMP_PIN, HIGH);
    delay(5000); // Watering duration
    digitalWrite(PUMP_PIN, LOW);
    Serial.println("Watering complete.");
  }
}

// Handling both manual pump control & moisture threshold update on V3
BLYNK_WRITE(V3) { 
    int value = param.asInt();
    if (value == 1) {  // If button pressed, turn on pump
        Serial.println("Manual watering started");
        digitalWrite(PUMP_PIN, HIGH);
        delay(5000);
        digitalWrite(PUMP_PIN, LOW);
        Serial.println("Manual watering finished");
        Blynk.virtualWrite(V3, 0); // Reset button in app
    } else {  
        moistureThreshold = value; // Update threshold if different value received
        Serial.print("New Moisture Threshold Set: ");
        Serial.println(moistureThreshold);
    }
}
