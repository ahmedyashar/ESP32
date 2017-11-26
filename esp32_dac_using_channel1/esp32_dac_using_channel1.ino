// dac ch1 = 25
// dac ch2 = 26
#include <Wire.h>
#include <driver/dac.h>
String incoming;
int n;
void setup(void) {
  Serial.begin(57600);
}
void loop(void) {
  while (Serial.available()) {
    incoming = Serial.read();
    n = incoming.toInt();
    Serial.println(n);
    dac_out_voltage(DAC_CHANNEL_1, n);
  }
}
