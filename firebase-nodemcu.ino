#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "api-project-547390180617.firebaseio.com"
#define FIREBASE_KEY "12scwmtVYceHitJNXZXdHPwMxTKmR5hLhf5F13Lo"
#define WIFI_SSID       "kark"
#define WIFI_PASSWORD   "0000000a"

void setup() {
  Serial.begin(9600);
  Serial.println(WiFi.localIP());
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_KEY);
  Firebase.set("name", "Hello..! You");
  // Do something
}

void loop() {
  
  // Do something
  
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["sensor"] = "gps";
  root["time"] = 1351824120;
  
  JsonArray& data = root.createNestedArray("data");
  data.add(48.756080, 6);  // 6 is the number of decimals to print
  data.add(2.302038, 6);   // if not specified, 2 digits are printed
  
  root.printTo(Serial);
  Serial.println();

}
