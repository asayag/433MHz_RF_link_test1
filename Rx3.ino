// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
//#include <RadioHead.h>
// Include dependant SPI Library
#include <SPI.h>

// Create Amplitude Shift Keying Object
//RH_ASK rf_driver;
RH_ASK rf_driver(2000, 15, 14, 0);
void setup()
{
  Serial.begin(9600);
  // Initialize ASK Object
  rf_driver.init();
}

int value = 0;

void loop()
{
  // Set buffer to size of expected message
  uint8_t buf[100]="";
  uint8_t buflen = sizeof(buf);
  // Check if received packet is correct size
  if (rf_driver.recv(buf, &buflen))
  {

    // Message received with valid checksum
    Serial.print("Message Received: ");
    Serial.println((char*)buf);
  }

}
