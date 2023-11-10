//2531
//04

#include <MultiSensorArray.h>

const uint8_t sensorAddresses[] = {0x40, 0x40, 0x40, 0x40, 0x40, 0x40}; // Addresses for two sensors
const uint8_t muxAddress = 0x70;

MultiSensorArray sensorArray;

void setup() {
    Serial.begin(115200);
    sensorArray.begin(muxAddress);
    Serial.println("Reading distances from sensors:");
}

void loop() {
    for (int sensorIndex = 0; sensorIndex < sizeof(sensorAddresses) / sizeof(sensorAddresses[0]); sensorIndex++) {
        int distance = sensorArray.readDistance(sensorIndex);
        int count = 0;
        if (distance != -1) {
            count++;
            Serial.print("\r                    ");
            Serial.print("\r");
            Serial.print("Sensor ");
            Serial.print(sensorIndex);
            Serial.print(" Distance: ");
            Serial.print(distance);
            Serial.println(" cm");
        } else {
            Serial.println("Error reading sensor.");
        }

        delay(500); // Delay before reading the next sensor
    }
}
