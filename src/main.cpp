/*
  ESP32 Web Server - STA Mode
  by Mohammadreza Akbari @ Electropeak
*/

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

//SSID & Password
const char* ssid = "noShar3";
const char* password = "holacomoestas";

WebServer server(80); //Object of WebServer (HTTP Port, 80 is default)

String HTML = "<!DOCTYPE html>\
<html>\
<head>\
  <meta charset='UTF-8'>\
  <meta name='viewport' content='width=device-width, initial-scale=1.0'>\
  <title>WEB Server - ESP32</title>\
</head>\
<body>\
  <div class='container'>\
    <header>\
      <h1 class='title'>ESP32 WEB Server</h1>\
    </header>\
    <section class='interaction'>\
      <a href='#'' class='button'>Turn OFF</a>\
      <p>GPIO 26</p>\
      <hr>\
      <p>State OFF</p>\
      <a href='#'' class='button'>Turn OFF</a>\
      <p>GPIO 27</p>\
      <hr>\
      <p>State OFF</p>\
    </section>\
  </div>\
  <footer>\
    <p class='footer'>Made By Simon Clemente</p>\
  </footer>\
</body>\
</html>";

// Handle root url (/)
void handle_root()
{
  server.send(200, "text/html", HTML);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Connecting to...");
  Serial.println(ssid);

  //Connect to your wi-fi modem
  WiFi.begin(ssid, password);

  //Check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {

    delay(1000);
    Serial.print(".");

  }

  Serial.println("");
  Serial.println("WiFi connected successfully");
  Serial.print("Got IP: ");
  Serial.println(WiFi.localIP()); //Show Esp32 IP on monitor 

  server.on("/", handle_root);

  server.begin();
  Serial.println("HTTP server Started");
  delay(100);
  
}

void loop() {

  server.handleClient();
  
}

