#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// We should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "A1KfQb9-vLYn6yJ2xfKPfJxK0bT3DFX3";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Sanglap";
char pass[] = "EEE1707046";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
