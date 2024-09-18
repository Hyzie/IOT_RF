#include "HardwareSerial.h"

HardwareSerial MySerial(1);  // Use UART1

void setup() {
  // Initialize UART1 at 9600 baud, with RX on GPIO 16 and TX on GPIO 17
  MySerial.begin(9600, SERIAL_8N1, 16, 17);
  Serial.begin(115200);  // Initialize the main serial for debugging

  Serial.println("Starting Receiver...");
}

void loop() {
  if (MySerial.available()) {
    // Read until newline ('\n') to capture one message at a time
    String receivedMessage = MySerial.readStringUntil('\n');
    if (receivedMessage.length() > 0) {
      Serial.println("Data received: " + receivedMessage);  // Debugging
    }
  }
  delay(100);  // Small delay to avoid rapid looping
}
