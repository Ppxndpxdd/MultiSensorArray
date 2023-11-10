// MultiSensorArray.h

#ifndef MultiSensorArray_h
#define MultiSensorArray_h

#include <Wire.h>

class MultiSensorArray {
public:
    MultiSensorArray(); // Declaration only

    void begin(uint8_t muxAddress);
    int readDistance(uint8_t sensorIndex);

private:
    uint8_t muxAddress;
};

// Declare the sensorAddresses array here
extern const uint8_t sensorAddresses[];

#endif
