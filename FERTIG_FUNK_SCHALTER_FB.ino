#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <SPI.h>
#include <ESP8266HTTPClient.h>

#define USE_SERIAL Serial

#define SERIAL_DEBUG 1          //ausgeführte Befehle auf die Serielle Schnittstelle ausgeben
#define SWITCHSERVER_PORT 9274  //Port des Schaltservers
//Funktionsdeklarationen
String readRequest(WiFiClient* client);

//Initalisieren
WiFiServer server = WiFiServer(SWITCHSERVER_PORT);
WiFiClient client;

//==========================KeyPad-SETTINGS=============================
#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'D', '#', '0', '*'},
  {'C', '9', '8', '7'},
  {'B', '6', '5', '4'},
  {'A', '3', '2', '1'}
};
byte rowPins[ROWS] = {2, 0, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {15, 13, 12, 14}; //connect to the column pinouts of the keypad
// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//===========================WIFI-SETTINGS==============================
IPAddress ip(192, 168, 178, 250);
const char* ssid     = "WLAN NAME";
const char* password = "WLAN PASSWORT";
ESP8266WiFiMulti WiFiMulti;
HTTPClient http;
//===============================SETUP==================================
void setup() {

  Serial.begin(9600);
  delay(10);
  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.flush();
  delay(200);

  // allow reuse (if server supports it)
  http.setReuse(true);
  server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());
}

void loop()
{
  keypadin();
  Switchserver();
}

void keypadin()
{

  char key = kpd.getKey();
  if (key) // Check for a valid key.
  {
    switch (key)
    {
      //===================================================================
      case '1':
        Serial.println(key);
        //===============================http senden=========================
        if ((WiFiMulti.run() == WL_CONNECTED)) {
          http.begin(„Hier muss der Link Rein der geklickt werden soll am besten „Toggeln“);
          int httpCode = http.GET();
          http.end();
        }
        //===============================http senden===================================

        break;
      case '2':
        Serial.println(key);
        //===============================http senden==========================
        if ((WiFiMulti.run() == WL_CONNECTED)) {
          http.begin(„Hier muss der Link Rein der geklickt werden soll am besten „Toggeln“);
          int httpCode = http.GET();
          http.end();
        }
        //===============================http senden===================================
        break;

      case '3':
        Serial.println(key);
        //===============================http senden=================================

        if ((WiFiMulti.run() == WL_CONNECTED)) {
          http.begin(„Hier muss der Link Rein der geklickt werden soll am besten „Toggeln“);
          int httpCode = http.GET();
          http.end();
        }
        //===============================http senden===================================

        break;
      case 'A':
        Serial.println(key);

        //===============================http senden==========================

        if ((WiFiMulti.run() == WL_CONNECTED)) {
          http.begin(„Hier muss der Link Rein der geklickt werden soll am besten „Toggeln“);
          int httpCode = http.GET();
          http.end();
        }
        //===============================http senden===================================
        break;
      //=================================================================
      case '4':
        Serial.println(key);

        //===============================http senden=======================

        if ((WiFiMulti.run() == WL_CONNECTED)) {
          http.begin(„Hier muss der Link Rein der geklickt werden soll am besten „Toggeln“);
          int httpCode = http.GET();
          http.end();
        }
        //===============================http senden===================================

        break;
      case '5':
        Serial.println(key);

        //===============================http senden======================

        if ((WiFiMulti.run() == WL_CONNECTED)) {
          http.begin(„Hier muss der Link Rein der geklickt werden soll am besten „Toggeln“);
          int httpCode = http.GET();
          http.end();
        }
        //===============================http senden===================================

        break;
      case '6':
        Serial.println(key);

        //===============================http senden=====================

        if ((WiFiMulti.run() == WL_CONNECTED)) {
          http.begin(„Hier muss der Link Rein der geklickt werden soll am besten „Toggeln“);
          int httpCode = http.GET();
          http.end();
        }
        //===============================http senden===================================
        break;
      case 'B':
        Serial.println(key);

        //===============================http senden====================

        if ((WiFiMulti.run() == WL_CONNECTED)) {
          http.begin(„Hier muss der Link Rein der geklickt werden soll am besten „Toggeln“);
          int httpCode = http.GET();
          http.end();
        }
        //===============================http senden===================================
        break;
      case '7':
        Serial.println(key);

        //===============================http senden=====================

        if ((WiFiMulti.run() == WL_CONNECTED)) {
          http.begin(„Hier muss der Link Rein der geklickt werden soll am besten „Toggeln“);
          int httpCode = http.GET();
          http.end();
        }
        //===============================http senden===================================

        break;
      case '8':
        Serial.println(key);

        //========================================================================

        //===============================http senden=====================

        if ((WiFiMulti.run() == WL_CONNECTED)) {
          http.begin(„Hier muss der Link Rein der geklickt werden soll am besten „Toggeln“);
          int httpCode = http.GET();
          http.end();
        }
        //===============================http senden===================================

        break;
      case '9':
        Serial.println(key);

        //===============================http senden=====================

        if ((WiFiMulti.run() == WL_CONNECTED)) {
          http.begin(„Hier muss der Link Rein der geklickt werden soll am besten „Toggeln“);
          int httpCode = http.GET();
          http.end();
        }
        //===============================http senden===================================

        break;
      case 'C':
        Serial.println(key);

        //===============================http senden=====================

        if ((WiFiMulti.run() == WL_CONNECTED)) {
          http.begin(„Hier muss der Link Rein der geklickt werden soll am besten „Toggeln“);
          int httpCode = http.GET();
          http.end();
        }
        //===============================http senden===================================
        break;
      case '*':
        Serial.println(key);


        //==========================================================================

        //===============================http senden=====================

        if ((WiFiMulti.run() == WL_CONNECTED)) {
          http.begin(„Hier muss der Link Rein der geklickt werden soll am besten „Toggeln“);
          int httpCode = http.GET();
          http.end();
        }
        //===============================http senden===================================

        break;
      case '0':
        Serial.println(key);

        //===============================http senden=====================

        if ((WiFiMulti.run() == WL_CONNECTED)) {
          http.begin(„Hier muss der Link Rein der geklickt werden soll am besten „Toggeln“);
          int httpCode = http.GET();
          http.end();
        }
        //===============================http senden===================================
        break;
      case '#':
        Serial.println(key);

        //===============================http senden=====================

        if ((WiFiMulti.run() == WL_CONNECTED)) {
          http.begin(„Hier muss der Link Rein der geklickt werden soll am besten „Toggeln“);
          int httpCode = http.GET();
          http.end();
        }
        //===============================http senden===================================
        break;
      case 'D':
        Serial.println(key);

        //===============================http senden=====================

        if ((WiFiMulti.run() == WL_CONNECTED)) {
          http.begin(„Hier muss der Link Rein der geklickt werden soll am besten „Toggeln“);
          int httpCode = http.GET();
          http.end();
        }
        //===============================http senden===================================
        break;

      default:
        Serial.println(key);
    }
  }
}

void Switchserver() {

  size_t size;
  if (WiFiClient client = server.available()) {


    //Anfrage empfangen
    String request = readRequest(&client);

    //Debug Ausgabe
    if (SERIAL_DEBUG) {

      Serial.println("request " + request);
    }

    // Variablen Aufteilen
    // Data is now available in pieces array
    // pieces[0] is first item
    // pieces[1] is second item, and so on
    // You can call toInt() on the data to convert it to an int
    // ex. int value = pieces[0].toInt();
    const int numberOfPieces = 6;
    String pieces[numberOfPieces];
    int counter = 0;
    int lastIndex = 0;

    for (int i = 0; i < request.length(); i++) {

      if (request.substring(i, i + 1) == ":") {
        pieces[counter] = request.substring(lastIndex, i);
        lastIndex = i + 1;
        counter++;
      }
    }
    pieces[counter] = request.substring(lastIndex, request.length() + 1);

    //Anfrage bearbeiten
    int type = pieces[0].toInt();
    if (type == 2) {

      //GPIO Ausgang schalten Typ 2
      //(Typ[0]:Pin[1]:Befehl[2]) + Leerzeichen am Ende
      int pin = pieces[1].toInt();
      int command = pieces[2].toInt();

      pinMode(pin, OUTPUT);
      if (command == 1) {

        digitalWrite(pin, HIGH);
      } else {

        digitalWrite(pin, LOW);
      }

      //Debug Ausgabe
      if (SERIAL_DEBUG) {

        Serial.print("write ");
        Serial.print(pin);
        Serial.print(" ");
        Serial.println(command);
      }
    } else if (type == 3) {

      //GPIO Eingang schalten Typ 3
      //(Typ[0]:Pin[1]) + Leerzeichen am Ende
      int pin = pieces[1].toInt();

      pinMode(pin, INPUT);
      int state = digitalRead(pin);
      client.println(state);
      client.flush();

      //Debug Ausgabe
      if (SERIAL_DEBUG) {

        Serial.print("read ");
        Serial.print(pin);
        Serial.print(" state ");
        Serial.println(state);
      }
    }

    //verbindung beenden
    client.stop();

  }

}

String readRequest(WiFiClient* client) {

  String request = "";
  // Loop while the client is connected.
  while (client->connected()) {
    // Read available bytes.
    while (client->available()) {
      // Read a byte.
      char c = client->read();

      // Exit loop if end of line.
      if ('\n' == c) {
        return request;
      }
      // Add byte to request line.
      request += c;
    }
  }
  return request;
}
