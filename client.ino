#include <WiFi.h>

const char* ssid = "Phan Gia 1";
const char* password = "0913513339";
const char* host = "192.168.0.103"; // IP của ESP32 Server

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println("Connected to WiFi");
}

void loop() {
  WiFiClient client;
  if (client.connect(host, 3333)) {
    client.println("123");
    Serial.println("Sent data!");
    client.stop();
  } else {
    Serial.println("Connection failed.");
  }

  delay(3000);
}
