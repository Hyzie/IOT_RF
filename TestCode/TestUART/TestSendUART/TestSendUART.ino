#include "HardwareSerial.h"

HardwareSerial MySerial(1);  // Use UART1

void setup() {
  // Initialize UART1 at 9600 baud, with RX on GPIO 16 and TX on GPIO 17
  MySerial.begin(9600, SERIAL_8N1, 16, 17);
  Serial.begin(115200);  // Initialize the main serial for debugging

  delay(1000);
  Serial.println("Starting Transmitter...");
}

void loop() {
  String message = "Test UART OPTIMA ROBOTICS";
  MySerial.println(message);  // Send data via UART1
  Serial.println("Data sent: " + message);  // Debugging

  delay(1000);  // Delay to simulate periodic transmission
}
