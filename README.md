Also hier mal meine Erklärung zu diesem Projekt : 

Ihr Braucht einen Esp12  und ein Keypad 4x4  und eine Stromversorgung 5V 


Hier der Code des Projekts: https://github.com/jannek09/Wlan-Funk-keypad.git


Zur Beleuchtung habe ich ein altes Handy Display genommen. Dieses wird über einen Setup Wandler mit ström versorgt und durch den Podien kann man diesen den auch in der Helligkeit steuern, für die nacht sehr praktisch.

Wlan muss in der Datei :an dieser stelle eingetragen werden:

const char* ssid     = "WLAN NAME";
const char* password = "WLAN PASSWORT";

Dieses Keypad muss Laut Datei an diesen Pins angeschlossen werden :

{2, 0, 4, 5}; //connect to the row pinouts of the keypad
{15, 13, 12, 14}; //connect to the column pinouts of the keypad

Hier müsst ihr einen Togen Code eintragen für jede Taste Extra :

Die taste wird über das „case ‚1‘ „ beschrieben 

 if((WiFiMulti.run() == WL_CONNECTED)) {
        http.begin(„Hier muss der Link Rein der geklickt werden soll am besten „Toggeln“);
        int httpCode = http.GET();
        http.end();
    }

Das war es. Mehr ist eigentlich nicht zu machen.
