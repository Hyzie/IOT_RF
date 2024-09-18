/*
  Transmitter Code for Sending String "Hoang" to Receiver
  Demonstrates simple TX operation with an ESP32.
  Radio    ESP32 module
  CE    -> 4
  CSN   -> 5
  MOSI  -> 23
  MISO  -> 19
  SCK   -> 18
  IRQ   -> No connection
  VCC   -> No more than 3.6 volts
  GND   -> GND
*/

#include "SPI.h"
#include "NRFLite.h"

const static uint8_t RADIO_ID = 5;
const static uint8_t DESTINATION_RADIO_ID = 0;
const static uint8_t PIN_RADIO_CE = 4;
const static uint8_t PIN_RADIO_CSN = 5;
const static uint8_t PIN_RADIO_MOSI = 23;
const static uint8_t PIN_RADIO_MISO = 19;
const static uint8_t PIN_RADIO_SCK = 18;

struct __attribute__((packed)) RadioPacket // Note the packed attribute for proper memory alignment.
{
    uint8_t FromRadioId;
    char Message[6];  
};

NRFLite _radio;
RadioPacket _radioData;

void setup()
{
    Serial.begin(115200);
    
    // Configure SPI pins.
    SPI.begin(PIN_RADIO_SCK, PIN_RADIO_MISO, PIN_RADIO_MOSI, PIN_RADIO_CSN);
    
    // Indicate to NRFLite that it should not call SPI.begin() during initialization since it has already been done.
    uint8_t callSpiBegin = 0;
    
    if (!_radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN, NRFLite::BITRATE2MBPS, 100, callSpiBegin))
    {
        Serial.println("Cannot communicate with radio");
        while (1); // Wait here forever.
    }

    // Set up the message to send
    _radioData.FromRadioId = RADIO_ID;
    strcpy(_radioData.Message, "Hoang");  
}

void loop()
{
    Serial.print("Sending message: ");
    Serial.println(_radioData.Message);
    
    if (_radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData)))
    {
        Serial.println("...Success");
    }
    else
    {
        Serial.println("...Failed");
    }

    delay(1000); // Send every second
}
