// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

// Additional comments, and slight updates by John M. Wargo

#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to

// Uncomment the line for the specific hardware you're using
// commenting out the remaining lines
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Create DHT sensor object for the specific hardware
// configuration we're using
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
  // Wait two seconds between measurements
  delay(2000);

  // ==========================================================================
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  // ==========================================================================
  // Read the humidity
  float h = dht.readHumidity();
  // Read temperature in degrees Celsius (the default)
  float t = dht.readTemperature();
  // Another way to do this is:
  // float t = dht.readTemperature(false);
  // Read temperature in degrees Fahrenheit 
  // (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Make sure the sketch was able to read values from the sensor before
  // continuing. the return exits the loop (try again)
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in degrees Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in degrees Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  // Write the resulting data (properly formatted) to the serial port
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
