#include "BluetoothA2DP_Sink.h"
#include "BluetoothSerial.h"

BluetoothA2DPSink a2dp_sink;
BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_A2DP_Sink");
  Serial.println("Bluetooth A2DP Sink");

  a2dp_sink.set_pin("1234"); // Replace with your own PIN code
  a2dp_sink.start("ESP32 Speaker"); // Replace with your own device name

  Serial.println("A2DP Sink started");
}

void loop() {
  if (a2dp_sink.connected()) {
    Serial.println("Connected");
  } else {
    Serial.println("Disconnected");
  }

  if (SerialBT.available()) {
    a2dp_sink.write(SerialBT.read());
  }
}
