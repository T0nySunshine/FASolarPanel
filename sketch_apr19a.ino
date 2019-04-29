

#include <ESP8266WiFi.h>  

const char *SSID="o2-WLAN61"; //WLAN-Name
const char *Passwort="wlanmenzinger"; //WLAN-Schlüssel
int Sensorwert = 0;
int eingang = A0;






void setup() {
  Serial.begin(9600);
  WiFi.begin(SSID, Passwort);
  int retries=0;
  while ((WiFi.status()!=WL_CONNECTED)&&(retries<100)){
    retries++;
    delay(200);
    Serial.print(".");
  }
  if (WiFi.status()==WL_CONNECTED) {
    Serial.println(F("WiFi connected"));
    Serial.println(WiFi.localIP());
  }
}

void loop() {
  Sensorwert = analogRead(eingang);
  Serial.print("Sensorwert: ");
  Serial.println(Sensorwert);
  delay(3000);
}
