#include "MultiSensorArray.h"

// Include the external declaration for sensorAddresses
extern const uint8_t sensorAddresses[];

MultiSensorArray::MultiSensorArray() {}

void MultiSensorArray::begin(uint8_t muxAddress) {
    this->muxAddress = muxAddress;
    Wire.begin();
}

int MultiSensorArray::readDistance(uint8_t sensorIndex) {
    Wire.beginTransmission(muxAddress);
    Wire.write(1 << sensorIndex);
    int ans = Wire.endTransmission();

    if (ans == 0) {
        Wire.beginTransmission(sensorAddresses[sensorIndex]);
        Wire.write(0x5E);
        ans = Wire.endTransmission();

        if (ans == 0) {
            ans = Wire.requestFrom(static_cast<uint8_t>(sensorAddresses[sensorIndex]), static_cast<uint8_t>(2));
            if (ans == 2) {
                uint8_t c[2];
                c[0] = Wire.read();
                c[1] = Wire.read();
                ans = ((c[0] * 16 + c[1]) / 16) / 4;
            }
        }
    }

    return ans;
}
