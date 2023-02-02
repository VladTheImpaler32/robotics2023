#include <Keyboard.h>
#include <KeyboardLayout.h>
#include <Keyboard_da_DK.h>
#include <Keyboard_de_DE.h>
#include <Keyboard_es_ES.h>
#include <Keyboard_fr_FR.h>
#include <Keyboard_it_IT.h>
#include <Keyboard_sv_SE.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#ifndef APSSID
#define APSSID "Access Point"
#define APPSK  "thereisnopassword"
#endif

const char *ssid = APSSID;
const char *password = APPSK;

ESP8266WebServer server(80);

const char MAIN_page[] PROGMEM = R"=====(
<form action="/action_page">
MESSAGE:<input type="text" name="message" value="test">
<br><br>
<input type="submit" value="Submit">
)=====";

void handleRoot() {
  String a = MAIN_page;
  server.send(200, "text/html", a);
}

void formHandler() {
  String message = server.arg("message");
  Serial.print("Message: ");
  Serial.println(message);
  Keyboard.print(message);

  String s = "<a href='/'> Go Back </a>";
  server.send(200, "text/html", s);
}

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.on("/action_page", formHandler);
  server.begin();
  Serial.println("HTTP server started");

  Keyboard.begin();
}

void loop() {
  server.handleClient();
}
