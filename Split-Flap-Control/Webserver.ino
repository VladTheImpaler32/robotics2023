#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#ifndef STASSID
#define STASSID "TELUS4496"
#define STAPSK  "z8by22tyr9"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

ESP8266WebServer server(80);

const char MAIN_page[] PROGMEM = R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<style>body {display: flex;justify-content: center;align-items: center; background-color: #121212;} form {height: 80vh;} label {font-size: x-large; color: white;} input {font-size: large;}</style>
<form action="/action_page">
<label for='message'>MESSAGE:</label><input type="text" name="message" placeholder="type here">
<br><br>
<input type="submit" value="Submit">
)=====";

void handleRoot() {
  String a = MAIN_page;
  server.send(200, "text/html", a);
}

void formHandler() {
  String message = server.arg("message");
  message.toUpperCase();
  char firstLetter[message.length()];
  message.toCharArray(firstLetter, message.length()+1);
//  Serial.print("Message: ");
//  Serial.println(message);
  Serial.println();
  Serial.print("Letter: ");
  Serial.println(firstLetter[0]);

  goTo(firstLetter[0]);

//  String s = "<a href='/'> Go Back </a>";
  String s = "<script>window.location.href = '/';</script>";  
  server.send(200, "text/html", s);
}

void WiFiSetup() {
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  server.on("/action_page", formHandler);
  server.begin();
  Serial.println("HTTP server started");
}

void WiFiLoop() {
    server.handleClient();
}
