#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "*****";
const char* password = "******";

const char* mqtt_server = "********";  // hoặc IP local broker
const int mqtt_port = 1883;
const char* mqtt_topic = "esp32/data";

WiFiServer server(3333);
WiFiClient espClient;
PubSubClient mqttClient(espClient);

void reconnectMQTT() {
  while (!mqttClient.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (mqttClient.connect("ESP32ServerClient")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  mqttClient.setServer(mqtt_server, mqtt_port);

  server.begin();
  Serial.println("TCP Server started...");
}

void loop() {
  if (!mqttClient.connected()) {
    reconnectMQTT();
  }
  mqttClient.loop();

  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client connected");
    while (client.connected()) {
      if (client.available()) {
        String data = client.readStringUntil('\n');
        Serial.print("Received from ESP32: ");
        Serial.println(data);

        // Gửi lên MQTT Broker
        mqttClient.publish(mqtt_topic, data.c_str());
        Serial.println("Data sent to MQTT Broker!");
      }
    }
    client.stop();
    Serial.println("Client disconnected");
  }
}
