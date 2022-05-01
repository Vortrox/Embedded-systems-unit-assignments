#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTTYPE DHT11

const int signalPin = D4;
DHT dht(signalPin, DHTTYPE);

void setup() {
    dht.begin();
}

void loop() {
    float t = dht.readTemperature();
    Particle.publish("temperature", String(t), PRIVATE);
    delay(30000);
}