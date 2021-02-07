#include <WiFiClientSecure.h>
#include <PubSubClient.h>
 
const char* ssid = "";
const char* password =  "";
const char* mqttServer = "";
const int mqttPort = 8883;
const char* mqttUser = "";
const char* mqttPassword = "";

WiFiClientSecure espClient;
PubSubClient client(espClient);

void setup() {
 
  Serial.begin(115200);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  
  client.setServer(mqttServer, mqttPort);
  
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP32Client", mqttUser, mqttPassword )) {
      Serial.println("connected");
    } else {
      Serial.println("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}
 
void loop() {
  int pulseFromAppleWatch = 68 + random(-5,5);
  char str[8];
  itoa(pulseFromAppleWatch, str, 10);
  client.publish("iot/funny-mendeleev/vitals/pulse", str);
  delay(6000);
  const char* ecgFromAppleWatch = "No Signs of Atrial fibrillation";
  client.publish("iot/funny-mendeleev/vitals/ecg", ecgFromAppleWatch);
  delay(6000);
  client.loop();
}
