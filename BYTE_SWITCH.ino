
#define BLYNK_TEMPLATE_ID   "TMPL3cgkU_P0R"
#define BLYNK_TEMPLATE_NAME "RemoteFan"
#define BLYNK_AUTH_TOKEN    "TPClwZrF4kRCWGa3Dy8AxqZIX1Za4Ce-"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials
char ssid[] = "Infinix gt 10 pro";       // <-- Enter your WiFi name
char pass[] = "yourdream";   // <-- Enter your WiFi password

// Relay pins
#define RELAY1 5
#define RELAY2 18
#define RELAY3 19
#define RELAY4 21

// Blynk virtual pins
#define VPIN_RELAY1 V1
#define VPIN_RELAY2 V2
#define VPIN_RELAY3 V3
#define VPIN_RELAY4 V4

void setup()
{
  Serial.begin(115200);

  // Relay pin setup
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  // Set all relays OFF initially
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, HIGH);

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// Relay 1 control
BLYNK_WRITE(VPIN_RELAY1) {
  digitalWrite(RELAY1, param.asInt() ? LOW : HIGH);
}

// Relay 2 control
BLYNK_WRITE(VPIN_RELAY2) {
  digitalWrite(RELAY2, param.asInt() ? LOW : HIGH);
}

// Relay 3 control
BLYNK_WRITE(VPIN_RELAY3) {
  digitalWrite(RELAY3, param.asInt() ? LOW : HIGH);
}

// Relay 4 control
BLYNK_WRITE(VPIN_RELAY4) {
  digitalWrite(RELAY4, param.asInt() ? LOW : HIGH);
}

void loop()
{
  Blynk.run();
}
