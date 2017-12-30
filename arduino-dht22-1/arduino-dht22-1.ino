// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain
// Additional comments by John M. Wargo

#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to

// Uncomment the line for the specific hardware you're using
//commenting out the other lines
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Initialize DHT sensor library for the specific hardware configuration
// we're using
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // initialize the serial communication link between the
  // Arduino device and the computer system running the Serial Monitor
  Serial.begin(9600);
  Serial.println("DHT Sensor Data");

  // Initialize the dht object
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("C ");
  Serial.print(f);
  Serial.print("F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print("C ");
  Serial.print(hif);
  Serial.println("F");
}
