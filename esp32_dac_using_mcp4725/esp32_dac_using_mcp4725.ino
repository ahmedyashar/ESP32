// scl=22
// sda=21


#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <driver/dac.h>
String incoming;
int n;
int in_min = 0;
int in_max = 255;
int out_min = 0;
int out_max = 4095;
Adafruit_MCP4725 dac; // constructor
void setup(void) {
  Serial.begin(57600);
  dac.begin(0x62); // The I2C Address: Run the I2C Scanner if you're not sure
}
void loop(void) {
  while (Serial.available()) {
    incoming = Serial.read();
    n = incoming.toInt();
    Serial.println(n);
    int out = (n - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    dac.setVoltage(out, false);
  }
}
